// Fill out your copyright notice in the Description page of Project Settings.


#include "BlackHole.h"
#include "Engine.h"
#include "G1213AlejCharacter.h"
#include "G1213AlejProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Particles/ParticleSystem.h"

// Sets default values
ABlackHole::ABlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	RootComponent = MeshComponent;
	MeshComponent->SetRelativeScale3D(FVector(1, 1, 0.5f));

	MeshComponent->OnComponentHit.AddDynamic(this, &ABlackHole::OnHit);

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	Distance = 300;

	Period = 2;

	StrongForce = 100000;
}

// Called when the game starts or when spawned
void ABlackHole::BeginPlay()
{
	Super::BeginPlay();

	Character = Cast<AG1213AlejCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	MaterialInstance = MeshComponent->CreateDynamicMaterialInstance(0);

	CollisionSphere->SetSphereRadius(Distance);
}

void ABlackHole::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (Cast<AG1213AlejCharacter>(OtherActor) != nullptr) 
	{
		if (MaterialInstance)
			MaterialInstance->SetScalarParameterValue(TEXT("Alpha"), 1.0f);
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &ABlackHole::Pulse, Period, true);
	}
}

void ABlackHole::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (MaterialInstance)
		MaterialInstance->SetScalarParameterValue(TEXT("Alpha"), 0.0f);

	GetWorld()->GetTimerManager().ClearTimer(timerHandle);
}

void ABlackHole::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (Cast<AG1213AlejProjectile>(OtherActor))
	{
		OtherActor->Destroy();
		Destroy();
	}
}

void ABlackHole::Pulse()
{
	Character->GetCharacterMovement()->AddImpulse(Character->GetActorForwardVector() * FVector(StrongForce, StrongForce, 0.0f));
	
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystem, GetTransform());
}

// Called every frame
void ABlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

