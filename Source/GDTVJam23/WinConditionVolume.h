// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "WinConditionVolume.generated.h"

UCLASS()
class GDTVJAM23_API AWinConditionVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWinConditionVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxComponent;

	UFUNCTION()
	void OnBoxBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
		);

	UPROPERTY(EditAnywhere, Category="Gameplay")
	int32 BunniesRemain = 2;


	void CalculateRemainingBunnies();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
