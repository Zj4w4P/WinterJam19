// Fill out your copyright notice in the Description page of Project Settings.

#include "CrowCharacter.h"


// Sets default values
ACrowCharacter::ACrowCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACrowCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Error,TEXT("Is of workings"))
}

// Called every frame
void ACrowCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACrowCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
int ACrowCharacter::GetSlotsAvalible()
{
	return slotsAvaliable;
}
void ACrowCharacter::SetSlotsAvalible(int amountOfSpace)
{
	this->slotsAvaliable = amountOfSpace;
}

