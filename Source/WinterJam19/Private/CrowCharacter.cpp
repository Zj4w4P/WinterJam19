// Fill out your copyright notice in the Description page of Project Settings.

#include "CrowCharacter.h"
#include "Public/InteractionSystem/CorpseInteractable.h"
#include "Public/InteractionSystem/ShinyInteractable.h"


// Sets default values
ACrowCharacter::ACrowCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACrowCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Error,TEXT("Is of workings"))
}

void ACrowCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ACrowCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Feeding system scripts

void  ACrowCharacter::ForceFeedingFinish()
{
	toggleMovement.Broadcast(true);
}
void  ACrowCharacter::ForceFeedingStart()
{
	toggleMovement.Broadcast(false);
}


// Setters and getters

int ACrowCharacter::GetSlotsAvalible()
{
	return slotsAvaliable;
}
void ACrowCharacter::SetSlotsAvalible(int amountOfSpace)
{
	this->slotsAvaliable = amountOfSpace;
}
float  ACrowCharacter::GetCurrentSatedLevel()
{
	return currentSatedLevel;
}
void  ACrowCharacter::SetCurrentSatedLevel(float newSatedLevel)
{
	currentSatedLevel = newSatedLevel;
}
AShinyInteractable* ACrowCharacter::GetPickup() {
	return this->pickup;
}
void ACrowCharacter::SetPickup(AShinyInteractable* pickup) {
	this->pickup = pickup;
}
void ACrowCharacter::OnButtonReleased()
{
	UE_LOG(LogTemp, Warning, TEXT("On Button Released:: crow"));
	if (!eatenCorpseHeap) return;
	eatenCorpseHeap->OnButtonReleased(this);
	UE_LOG(LogTemp, Warning, TEXT("On Button Released:: crow was not empty"));
}



