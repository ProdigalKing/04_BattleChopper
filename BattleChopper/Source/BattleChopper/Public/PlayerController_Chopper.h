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
	AChopper* GetControlledChopper() const;

private:
};
