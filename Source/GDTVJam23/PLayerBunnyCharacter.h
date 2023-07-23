// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBunnyCharacter.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "PLayerBunnyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GDTVJAM23_API APLayerBunnyCharacter : public ABaseBunnyCharacter
{
	GENERATED_BODY()

public:
	APLayerBunnyCharacter();

protected:
	UPROPERTY(EditAnywhere, Category="Input")
	const UInputMappingContext* InputMapping;
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Move;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* IA_Look;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
