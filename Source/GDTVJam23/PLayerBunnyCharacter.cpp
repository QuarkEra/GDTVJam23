// Fill out your copyright notice in the Description page of Project Settings.


#include "PLayerBunnyCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

APLayerBunnyCharacter::APLayerBunnyCharacter()
{
	
}

void APLayerBunnyCharacter::Move(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		
		const FVector2D MoveValue = Value.Get<FVector2D>();
		const FRotator MoveRotation(0, Controller->GetControlRotation().Yaw, 0);

		if (MoveValue.Y != 0.f)
		{
			const FVector Direction = MoveRotation.RotateVector(FVector::ForwardVector);
			AddMovementInput(Direction, MoveValue.Y);
		}
		if (MoveValue.X != 0.f)
		{
			const FVector Direction = MoveRotation.RotateVector(FVector::RightVector);
			AddMovementInput(Direction, MoveValue.X);
		}
	}
}

void APLayerBunnyCharacter::Look(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		const FVector2D LookValue = Value.Get<FVector2D>();

		if (LookValue.X != 0.f)
		{
			AddControllerYawInput(LookValue.X);
		}
		if (LookValue.Y != 0.f)
		{
			AddControllerPitchInput(LookValue.Y);
		}
	}
}

void APLayerBunnyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	Super::SetupPlayerInputComponent(PlayerInputComponent);
	const APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (InputMapping != nullptr)
		{
			Subsystem->ClearAllMappings();
			Subsystem->AddMappingContext(InputMapping, 1);
	
			UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
			if (Input != nullptr)
			{
				Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APLayerBunnyCharacter::Move);
				Input->BindAction(IA_Look, ETriggerEvent::Triggered, this, &APLayerBunnyCharacter::Look);
			}
		}
	}
}
