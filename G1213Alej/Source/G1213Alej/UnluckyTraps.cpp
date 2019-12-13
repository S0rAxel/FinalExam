// Fill out your copyright notice in the Description page of Project Settings.


#include "UnluckyTraps.h"
#include "Components/StaticMeshComponent.h"
#include "G1213AlejCharacter.h"

// Sets default values
AUnluckyTraps::AUnluckyTraps()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	RootComponent = MeshComponent;

	MeshComponent->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));

	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetMassOverrideInKg(NAME_None, 200.0f);

	UnluckyValue = 4;
}

// Called when the game starts or when spawned
void AUnluckyTraps::BeginPlay()
{
	Super::BeginPlay();
	
}

void AUnluckyTraps::NotifyHit(UPrimitiveComponent* MyComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector Hitlocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	auto character = Cast<AG1213AlejCharacter>(OtherActor);

	if (character != nullptr)
	{
		if (character->level % UnluckyValue == 0)
			character->level -= 2;
		else
			character->level -= 1;

		Destroy();
	}
}

// Called every frame
void AUnluckyTraps::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

