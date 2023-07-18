// Fill out your copyright notice in the Description page of Project Settings.


#include "WinConditionVolume.h"

#include "GameFramework/FloatingPawnMovement.h"
#include "GDTV_GameMode.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AWinConditionVolume::AWinConditionVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Win Volume"));
	RootComponent = BoxComponent;

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AWinConditionVolume::OnBoxBeginOverlap);
	
}

// Called when the game starts or when spawned
void AWinConditionVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWinConditionVolume::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const AActor* Bunny = OtherActor;
	if (Bunny != nullptr)
	{
		AController* BunnyAI = Bunny->GetInstigatorController();
		const AController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (BunnyAI != nullptr)
		{
			const APawn* AIPawn = BunnyAI->GetPawn();
			if (AIPawn != nullptr && BunnyAI != PlayerController)
			{
				UPawnMovementComponent* MoveComp = AIPawn->GetMovementComponent();
				MoveComp->StopMovementImmediately();
				BunnyAI->UnPossess();
				BunniesRemain--;
				CalculateRemainingBunnies();
			}
		}
	}
}

void AWinConditionVolume::CalculateRemainingBunnies() const
{
	if (BunniesRemain == 1)
 	{
		AGDTV_GameMode* GM = Cast<AGDTV_GameMode>(GetWorld()->GetAuthGameMode());
	    if (GM != nullptr)
	    {
		    GM->EndGame();
	    }
 	}
}

// Called every frame
void AWinConditionVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

