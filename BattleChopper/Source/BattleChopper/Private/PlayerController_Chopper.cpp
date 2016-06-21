// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleChopper.h"
#include "PlayerController_Chopper.h"

void APlayerController_Chopper::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("%s is running"), *GetName());
	AChopper* PlayerChopper = GetControlledChopper();
	if (PlayerChopper != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is controlling %s"), *GetName(), *PlayerChopper->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has not possessed an actor."), *GetName());
	}
}

AChopper* APlayerController_Chopper::GetControlledChopper() const
{
	return Cast<AChopper>(GetPawn());
}

