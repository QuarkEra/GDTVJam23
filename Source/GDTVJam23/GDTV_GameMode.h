// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Sound/SoundCue.h"
#include "GDTV_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class GDTVJAM23_API AGDTV_GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AGDTV_GameMode();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	USoundCue* BGMusic;

	
	
public:
	UFUNCTION()
	void EndGame();
	FTimerHandle EndGameDelay;
	UPROPERTY(EditAnywhere)
	FName EndCredit = "/Game/Maps/EndCredit.EndCredit";
	UFUNCTION()
	void MoveToEndCreditsScene() const;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	int32 BunniesRemain = 3;
	
};
