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
	USoundCue* BgMusic;

	// set up end game condition without manually updating the bunniesremaining variable
	UPROPERTY()
	TArray<AActor*> BunnyArray;
	
public:
	// endgame condition of bunnies to save
	// made un-editable as the GameMode now calculates number of bunnies in beginplay()
	UPROPERTY(VisibleAnywhere, Category="Gameplay")
	int32 BunniesRemain = 0;

	void CheckWinCondition();

	// while this is a one level gamejam game the name endgame is appropriate
	UFUNCTION()
	void EndGame();
	
	// timer to wait while message is displayed on screen
	FTimerHandle EndGameDelay;
	
	// level to load when timer ends
	UPROPERTY(EditAnywhere)
	FName EndCredit = "/Game/Maps/EndCredit.EndCredit";
	UFUNCTION()
	void MoveToEndCreditsScene() const;
	
};
