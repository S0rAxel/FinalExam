// Fill out your copyright notice in the Description page of Project Settings.


#include "SurpriseBox.h"
#include "Engine.h"
#include "G1213AlejCharacter.h"

// Sets default values
ASurpriseBox::ASurpriseBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASurpriseBox::BeginPlay()
{
	Super::BeginPlay();
	
	Character = Cast<AG1213AlejCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (Character != nullptr)
		Character->InputComponent->BindAction("OpenBox", IE_Pressed, this, &ASurpriseBox::OpenBox);
}

void ASurpriseBox::OpenBox()
{
	float randomNumber = FMath::FRandRange(0, 1);
	if (randomNumber >= ChanceA)
	{
		Character->level++;
		OpenBox();
	}
	else if (randomNumber < ChanceA && randomNumber > ChanceB)
	{ 
		Character->level--;
		OpenBox();
	}
	else if (randomNumber <= ChanceC)
		GEngine->AddOnScreenDebugMessage(1, 5, FColor::Green, TEXT("Open Boxes Stop"));
}

// Called every frame
void ASurpriseBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

