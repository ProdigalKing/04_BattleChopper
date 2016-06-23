// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleChopper.h"
#include "PlayerController_Chopper.h"

void APlayerController_Chopper::BeginPlay()
{
	Super::BeginPlay();
	
	AChopper* PlayerChopper = GetControlledChopper();
	if (!PlayerChopper)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has not possessed an actor."), *GetName());
	}
}

void APlayerController_Chopper::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AimAtCrossHairLocation();
}

AChopper* APlayerController_Chopper::GetControlledChopper() const
{
	return Cast<AChopper>(GetPawn());
}

void APlayerController_Chopper::AimAtCrossHairLocation() const
{
	FVector AimedAtLocation;

	if (LineTraceThroughCrosshairs(AimedAtLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Aiming at: %s"), *AimedAtLocation.ToString());
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Aiming at sky."));
	}
	return;
}

bool APlayerController_Chopper::LineTraceThroughCrosshairs(FVector & Out_AimedAtLocation) const
{
	bool WasFunctionSuccessful = false;

	//Need de-projected direction for line trace
	FVector DeprojectedDirection;
	if (GetDeprojectedDirection(DeprojectedDirection))
	{

		//Use DeprojectedDirection to LineTrace from cross hair to point in map, report hit
		UE_LOG(LogTemp, Warning, TEXT("Direction: %s"), *DeprojectedDirection.ToString());
		WasFunctionSuccessful = true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GetDeprojectedDirection unsuccessful."))
	}
	return false;
}

bool APlayerController_Chopper::GetDeprojectedDirection(FVector& Out_DeprojectedDirection) const
{
	//Need Viewport location for de-projection into world space
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector CameraDeprojectedLocation; //Need for functionality.  Throwaway variable.
	return (DeprojectScreenPositionToWorld((ViewportSizeX * CrossHairPositionX), (ViewportSizeY * CrossHairPositionY), CameraDeprojectedLocation, Out_DeprojectedDirection));
}