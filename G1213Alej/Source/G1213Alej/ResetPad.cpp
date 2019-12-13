// Fill out your copyright notice in the Description page of Project Settings.


#include "ResetPad.h"
#include "Engine.h"
#include "G1213AlejCharacter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AResetPad::AResetPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	RootComponent = MeshComponent;

	MeshComponent->SetRelativeScale3D(FVector(1, 1, 0.25f));

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	Distance = 200;

	Speed = 1;

	isActivated = false;
}

// Called when the game starts or when spawned
void AResetPad::BeginPlay()
{
	Super::BeginPlay();

	MaterialInstance = MeshComponent->CreateDynamicMaterialInstance(0);

	CollisionSphere->SetSphereRadius(Distance);
}

void AResetPad::NotifyHit(UPrimitiveComponent* MyComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector Hitlocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	MyComp = MeshComponent;

	auto character = Cast<AG1213AlejCharacter>(OtherActor);

	if (character != nullptr && !isActivated)
	{
		isActivated = true;

		if (MaterialInstance)
			MaterialInstance->SetScalarParameterValue(TEXT("Alpha"), 1.0f);

		if (character->level > 10)
			GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AResetPad::ResetLevelMinus, Speed, true);
		else if (character->level < 10)
			GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AResetPad::ResetLevelPlus, Speed, true);
	}
}

void AResetPad::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (isActivated)
		if (Cast<AG1213AlejCharacter>(OtherActor) != nullptr) 
		{
			isActivated = false;
			MaterialInstance->SetScalarParameterValue(TEXT("Alpha"), 0.0f);
		}
}

void AResetPad::ResetLevelPlus()
{
	Character->level++;
	if (Character->level == 10)
		GetWorld()->GetTimerManager().ClearTimer(timerHandle);
}

void AResetPad::ResetLevelMinus()
{
	Character->level--;
	if (Character->level == 10)
		GetWorld()->GetTimerManager().ClearTimer(timerHandle);
}

// Called every frame
void AResetPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

