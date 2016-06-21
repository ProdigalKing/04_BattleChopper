// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleChopper.h"
#include "AIController_Chopper.h"

void AAIController_Chopper::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("%s is running"), *GetName());
	AChopper* AIChopper = GetControlledChopper();
	if (AIChopper != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is controlling %s"), *GetName(), *AIChopper->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has not possessed an actor."), *GetName());
	}
}

AChopper* AAIController_Chopper::GetControlledChopper() const
{
	return Cast<AChopper>(GetPawn());
}
