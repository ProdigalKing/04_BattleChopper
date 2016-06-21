// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleChopper.h"
#include "Chopper.h"


// Sets default values
AChopper::AChopper()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChopper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChopper::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AChopper::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

