// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Chopper.h"
#include "GameFramework/PlayerController.h"
#include "PlayerController_Chopper.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECHOPPER_API APlayerController_Chopper : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere) float CrossHairPositionX = 0.5f;
	UPROPERTY(EditAnywhere) float CrossHairPositionY = 0.33333f;
	UPROPERTY(EditAnywhere) float ChopperTargetRange = 1000000.0f;
	AChopper* ControlledChopper = nullptr;
	AChopper* GetControlledChopper() const;
	void AimAtCrossHairLocation() const;

	//Line-Trace from crosshair in order to determine what controlled chopper is aiming at.
	bool LineTraceThroughCrosshairs(FVector& Out_AimedAtLocation) const;

	//Get de-projected direction to use for line-tracing.
	bool GetDeprojectedDirection(FVector& Out_DeprojectedLocation) const;
};
