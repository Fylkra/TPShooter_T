// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSCharacter.h"
#include "Engine/Engine.h"
#include "EngineGlobals.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ATPSCharacter::ATPSCharacter(const FObjectInitializer& ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Camera Boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));

	CameraBoom->SetupAttachment(RootComponent);

	// Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	//Take Control of lowest Player
	AutoPossessPlayer = EAutoReceiveInput::Player0;


	
}

// Called when the game starts or when spawned
void ATPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Using TPSCharacter"));
	}
}

// Called every frame
void ATPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &ATPSCharacter::MoveForward);

	InputComponent->BindAxis("MoveRight", this, &ATPSCharacter::MoveRight);

	InputComponent->BindAxis("LookUp", this, &ATPSCharacter::AddControllerPitchInput);

	InputComponent->BindAxis("Turn", this, &ATPSCharacter::AddControllerYawInput);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ATPSCharacter::OnStartJump);

	InputComponent->BindAction("Jump", IE_Released, this, &ATPSCharacter::OnStopJump);


}

void ATPSCharacter::MoveForward(float AxisValue)
{
	if ((Controller != NULL) && (AxisValue != 0.0f))
	{
		// Identify which way is forward.
		FRotator Rotation = Controller->GetControlRotation();

		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}

		// Add movement in that direction.
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);

		AddMovementInput(Direction, AxisValue);
	}

}

void ATPSCharacter::MoveRight(float AxisValue)
{
	if (Controller != NULL && AxisValue != 0.0f)
	{
		// Find out which way is Right.
		const FRotator Rotation = Controller->GetControlRotation();

		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

		// Add movement in that direction.
		AddMovementInput(Direction, AxisValue);

	}

}

void ATPSCharacter::OnStartJump()
{
	bPressedJump = true;
}

void ATPSCharacter::OnStopJump()
{
	bPressedJump = false;
}

