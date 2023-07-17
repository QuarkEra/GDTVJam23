// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GDTV_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class GDTVJAM23_API AGDTV_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void EndGame();
	FTimerHandle EndGameDelay;
	FName EndCredit = "/Game/Maps/EndCredit.EndCredit";
	UFUNCTION()
	void MoveToEndCreditsScene() const;
	
};
