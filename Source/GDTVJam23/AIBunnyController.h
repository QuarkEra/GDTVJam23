// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIBunnyController.generated.h"

/**
 * 
 */
UCLASS()
class GDTVJAM23_API AAIBunnyController : public AAIController
{
	GENERATED_BODY()

private:
	FVector LastKnownPlayerLocation = FVector::ZeroVector;
	UPROPERTY()
	APawn* PlayerPawn;
	UPROPERTY()
	AActor* PlayerActor;


public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;


};
