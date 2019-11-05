// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MenuProjectGameMode.h"
#include "Public/SCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMenuProjectGameMode::AMenuProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Player_Character/BP_Player_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
