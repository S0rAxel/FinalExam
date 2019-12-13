// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ResetPad.generated.h"

UCLASS()
class G1213ALEJ_API AResetPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResetPad();

	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere) class USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere) class AG1213AlejCharacter* Character;

	UPROPERTY(EditAnywhere) float Speed;

	UPROPERTY(EditAnywhere) float Distance;

private:
	UMaterialInstanceDynamic* MaterialInstance;

	FTimerHandle timerHandle;

	bool isActivated;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector Hitlocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	void ResetLevelPlus();
	void ResetLevelMinus();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
