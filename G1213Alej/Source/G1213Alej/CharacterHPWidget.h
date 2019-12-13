// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterHPWidget.generated.h"

/**
 * 
 */
UCLASS()
class G1213ALEJ_API UCharacterHPWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly) class AG1213AlejCharacter* Character;
};
