// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RarestCandy.generated.h"

UCLASS()
class G1213ALEJ_API ARarestCandy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARarestCandy();

	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere) class UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere)	class USoundBase* Sound;

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
