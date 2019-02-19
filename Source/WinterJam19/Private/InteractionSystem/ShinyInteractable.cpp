// Fill out your copyright notice in the Description page of Project Settings.

#include "ShinyInteractable.h"
#include "CrowCharacter.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"


void AShinyInteractable::BeginPlay()
{
	Super::BeginPlay();
	pointsGiven = UKismetMathLibrary::RandomIntegerInRange(minPointsGiven, maxPointsGiven);
}
void AShinyInteractable::OnInteraction(ACrowCharacter* crowCharacterptr)
{
	// it was already picked so you should not be able to pick it again
	if (this->bIsActive == false) return;
	// We have no slots avalible, so we cant pickup an item
	if (crowCharacterptr->GetSlotsAvalible() <= 0) return;
		// We attach element to the character mesh
	this->AttachToComponent(crowCharacterptr->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Dziob");
		// If someone else was carrying the shiny object, we should drop it!
	if (owningCrow)
	{
		owningCrow->SetSlotsAvalible(owningCrow->GetSlotsAvalible() + 1);
	}
		// The player is now owning shiny object! we should represent that
	if (this->owningCrow != NULL)
		owningCrow->SetSlotsAvalible(owningCrow->GetSlotsAvalible() + 1);
	this->owningCrow = crowCharacterptr;
		// Make slots unavalible for him
	crowCharacterptr->SetSlotsAvalible(crowCharacterptr->GetSlotsAvalible() - 1);
}