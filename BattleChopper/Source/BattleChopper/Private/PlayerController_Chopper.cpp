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
	UE_LOG(LogTemp, Warning, TEXT("Should Aim here...."));
	//LineTrace from cross hair to point in map, report hit
	//Return position
	return;
}
