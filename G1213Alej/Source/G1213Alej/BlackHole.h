// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"

UCLASS()
class G1213ALEJ_API ABlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackHole();

	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere) class USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere) class UParticleSystem* ParticleSystem;

	UPROPERTY(EditAnywhere) float Distance;

	UPROPERTY(EditAnywhere) float Period;

	UPROPERTY(EditAnywhere) float StrongForce;

private:
	FTimerHandle timerHandle;

	UMaterialInstanceDynamic* MaterialInstance;

	class AG1213AlejCharacter* Character;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION() void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void Pulse();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
