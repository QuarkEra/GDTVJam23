// Fill out your copyright notice in the Description page of Project Settings.


#include "ALandmine.h"

#include "GDTV_GameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AALandmine::AALandmine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//setup components
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	RootComponent = StaticMeshComponent;
	PointLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLightComponent->SetupAttachment(StaticMeshComponent);
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComponent->SetupAttachment(StaticMeshComponent);
	//setup overlapping component trigger
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AALandmine::OnSphereBeginOverlap);

	//setup explosion sound effect
	static ConstructorHelpers::FObjectFinder<USoundCue> SFX_ExplosionHelper(TEXT("/Script/Engine.SoundCue'/Game/Audio/Explosion_Cue.Explosion_Cue'"));
	SFX_Explosion = SFX_ExplosionHelper.Object;

}

// Called when the game starts or when spawned
void AALandmine::BeginPlay()
{
	Super::BeginPlay();
	
}

void AALandmine::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ensure not to do anything if either player or null ptr
	const AController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	AController* OtherController = OtherActor->GetInstigatorController();
	if (PlayerController == nullptr)
	{
		return;
	}
	if (OtherActor == nullptr)
	{
		return;
	}
	if (OtherController == nullptr)
	{
		return;
	}
	if (PlayerController == OtherController)
	{
		return;
	}
	
	if (OtherActor)
	{
		// handle sound, effects and destruction of actors
		UGameplayStatics::SpawnEmitterAtLocation(this,
			ExplosionEffect,
			GetActorLocation(),
			GetActorRotation(),
			true,
			EPSCPoolMethod::None,
			true
			);
		
		UGameplayStatics::PlaySoundAtLocation(this,
			SFX_Explosion,
			GetActorLocation(),
			GetActorRotation(),
			1,
			1,
			0
			);
		// destroy bunny
		OtherActor->Destroy();
		// destroy self
		Destroy();
		AGDTV_GameMode* GM = Cast<AGDTV_GameMode>(GetWorld()->GetAuthGameMode());
		if (GM != nullptr)
		{
			GM->BunniesRemain--;
			if (GM->BunniesRemain == 1)
			{
				GM->EndGame();			
			}
		}
	}
}

// Called every frame
void AALandmine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

