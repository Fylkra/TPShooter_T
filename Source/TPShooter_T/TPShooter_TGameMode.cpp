// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TPShooter_TGameMode.h"
#include "TPShooter_TCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATPShooter_TGameMode::ATPShooter_TGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
