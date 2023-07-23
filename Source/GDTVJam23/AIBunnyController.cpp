// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBunnyController.h"

#include "Kismet/GameplayStatics.h"

void AAIBunnyController::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	
}

void AAIBunnyController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (PlayerPawn != nullptr)
	{
		
		if (LineOfSightTo(PlayerPawn, FVector::ZeroVector, false))
		{
			LastKnownPlayerLocation = PlayerPawn->GetActorLocation();
			MoveToLocation(LastKnownPlayerLocation, 100, true, true, false, true, 0, true);
		}
	}
}

