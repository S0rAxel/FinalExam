// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "G1213AlejGameMode.h"
#include "G1213AlejHUD.h"
#include "G1213AlejCharacter.h"
#include "UObject/ConstructorHelpers.h"

AG1213AlejGameMode::AG1213AlejGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AG1213AlejHUD::StaticClass();
}
