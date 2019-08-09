// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TPSCharacter.generated.h"

UCLASS()
class TPSHOOTER_T_API ATPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Forward and Backwards Movement
	UFUNCTION(BlueprintCallable)
		void MoveForward(float AxisValue);

	// Left and Right Movement
	UFUNCTION(BlueprintCallable)
		void MoveRight(float AxisValue);

	UFUNCTION(BlueprintCallable)
		void OnStartJump();

	UFUNCTION(BlueprintCallable)
		void OnStopJump();





};
