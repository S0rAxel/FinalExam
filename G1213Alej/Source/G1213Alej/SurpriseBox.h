// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SurpriseBox.generated.h"

UCLASS()
class G1213ALEJ_API ASurpriseBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASurpriseBox();

private:
	class AG1213AlejCharacter* Character;
	
	float ChanceA = 0.5f;
	float ChanceB = 0.2f;
	float ChanceC = 0.2f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OpenBox();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
