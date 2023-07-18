// Fill out your copyright notice in the Description page of Project Settings.


#include "GDTV_GameMode.h"

#include "Kismet/GameplayStatics.h"

AGDTV_GameMode::AGDTV_GameMode()
{
	// setup audio cue for background music
	static ConstructorHelpers::FObjectFinder<USoundCue> BGAudio(TEXT("/Game/Audio/BG_Music_Cue.BG_Music_Cue"));
	BGMusic = BGAudio.Object;
}

void AGDTV_GameMode::BeginPlay()
{
	Super::BeginPlay();

	// play background music
	UGameplayStatics::PlaySound2D(this, BGMusic, 1,1, 0);
	
}

void AGDTV_GameMode::EndGame()
{
	//Once End Game function is called 3 second delay to Move To End Credit Scene function executes
	GetWorldTimerManager().SetTimer(EndGameDelay, this, &AGDTV_GameMode::MoveToEndCreditsScene, 3.0f, false, 3.0f);
}

void AGDTV_GameMode::MoveToEndCreditsScene() const
{
	// FName EndCredit set in header file in public, instance editable for testing
	UGameplayStatics::OpenLevel(this, EndCredit, true);
}
