// Fill out your copyright notice in the Description page of Project Settings.


#include "TPShooterGameMode.h"
#include "Engine/Engine.h"
#include "EngineGlobals.h"

ATPShooterGameMode::ATPShooterGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

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
