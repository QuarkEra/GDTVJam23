// Fill out your copyright notice in the Description page of Project Settings.


#include "GDTV_GameMode.h"

#include "Kismet/GameplayStatics.h"

void AGDTV_GameMode::EndGame()
{
	GetWorldTimerManager().SetTimer(EndGameDelay, this, &AGDTV_GameMode::MoveToEndCreditsScene, 3.0f, false, 3.0f);
	UE_LOG(LogTemp, Display, TEXT("EndGame called..."));
}

void AGDTV_GameMode::MoveToEndCreditsScene() const
{
	UGameplayStatics::OpenLevel(this, EndCredit, true);
}
