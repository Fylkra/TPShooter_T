// Fill out your copyright notice in the Description page of Project Settings.


#include "TPShooterGameMode.h"
#include "Engine/Engine.h"
#include "EngineGlobals.h"
#include "TPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATPShooterGameMode::ATPShooterGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set Default Pawn to BP_TPSCharacter
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn'/Game/BP_TPSCharacter3'"));

	if (PlayerPawnObject.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}

}

void ATPShooterGameMode::StartPlay()
{
	Super::StartPlay();

	StartMatch();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hello World!"));
	}
}
