// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "TPSCharacter.generated.h"

UCLASS()
class TPSHOOTER_T_API ATPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPSCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
		USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
		UCameraComponent* Camera;
		


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Forward and Backwards Movement
	UFUNCTION(BlueprintCallable, Category = "MovementControls")
		void MoveForward(float AxisValue);

	// Left and Right Movement
	UFUNCTION(BlueprintCallable, Category = "MovementControls")
		void MoveRight(float AxisValue);

	UFUNCTION(BlueprintCallable, Category = "MovementControls")
		void OnStartJump();

	UFUNCTION(BlueprintCallable, Category = "MovementControls")
		void OnStopJump();







};
