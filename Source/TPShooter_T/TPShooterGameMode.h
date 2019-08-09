// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TPShooterGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TPSHOOTER_T_API ATPShooterGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ATPShooterGameMode(const FObjectInitializer& ObjectInitializer);

	virtual void StartPlay() override;

	
};
