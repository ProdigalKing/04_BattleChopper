// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Chopper.h"
#include "AIController.h"
#include "AIController_Chopper.generated.h"

/**
 * 
 */
UCLASS()
class BATTLECHOPPER_API AAIController_Chopper : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	

private:
	AChopper* GetControlledChopper() const;
	AChopper* GetPlayerChopper() const;
};