// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Particles/ParticleEmitter.h"
#include "Sound/SoundCue.h"
#include "ALandmine.generated.h"

UCLASS()
class GDTVJAM23_API AALandmine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AALandmine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent * StaticMeshComponent;
	UPROPERTY(EditAnywhere, Category="Components")
	USphereComponent * SphereComponent;
	UPROPERTY(EditAnywhere, Category="Components")
	UPointLightComponent * PointLightComponent;

	UPROPERTY(EditAnywhere, Category="Sound Effects")
	USoundCue* SFX_Explosion;

	UPROPERTY(EditAnywhere, Category="Particle Effects")
	UParticleSystem* ExplosionEffect;

	UFUNCTION()
	void OnSphereBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
		);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
