// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleChopper.h"
#include "AIController_Chopper.h"

void AAIController_Chopper::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("%s is running"), *GetName());
	AChopper* AIChopper = GetControlledChopper();
	AChopper* PlayerChopper = GetPlayerChopper();
	if (AIChopper != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is controlling %s"), *GetName(), *AIChopper->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has not possessed an actor."), *GetName());
	}
	if (PlayerChopper != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is targetting %s"), *GetName(), *PlayerChopper->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has not Targetting an actor."), *GetName());
	}
}

AChopper* AAIController_Chopper::GetControlledChopper() const
{
	return Cast<AChopper>(GetPawn());
}

AChopper * AAIController_Chopper::GetPlayerChopper() const
{
	AChopper* PlayerChopper = nullptr;
	//TArray<AActor*> PlayerControllerActors = TArray<AActor*>();
	PlayerChopper = Cast<AChopper>(GetWorld()->GetFirstPlayerController()->GetPawn());

	return PlayerChopper;
}
