// Fill out your copyright notice in the Description page of Project Settings.


#include "RarestCandy.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "G1213AlejCharacter.h"

// Sets default values
ARarestCandy::ARarestCandy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("Mesh Component"));
	RootComponent = MeshComponent;
	MeshComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	CollisionBox->AttachToComponent(MeshComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CollisionBox->SetBoxExtent(FVector(60, 60, 60));
}

// Called when the game starts or when spawned
void ARarestCandy::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARarestCandy::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto character = Cast<AG1213AlejCharacter>(OtherActor);


	if (character != nullptr)
	{
		if (Sound != nullptr)
			UGameplayStatics::PlaySoundAtLocation(this, Sound, GetActorLocation());

		character->level += 1 + character->NumberOfCandies++;
		Destroy();
	}
}

// Called every frame
void ARarestCandy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->AddActorLocalRotation(FRotator(0, DeltaTime * 100.0f, 0));
}

