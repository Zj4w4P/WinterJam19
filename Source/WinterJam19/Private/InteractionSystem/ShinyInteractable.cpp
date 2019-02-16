// Fill out your copyright notice in the Description page of Project Settings.

#include "ShinyInteractable.h"
#include "CrowCharacter.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h "



void AShinyInteractable::OnInteraction(ACrowCharacter* crowCharacterptr)
{
	// We have no slots avalible, so we cant pickup an item
	if (crowCharacterptr->GetSlotsAvalible() <= 0) return;
		// We attach element to the character mesh
	this->AttachToComponent(crowCharacterptr->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "Dziob");
		// The player is now owning shiny object! we should represent that
	this->owningCrow = crowCharacterptr;
		// Make slots unavalible for him
	crowCharacterptr->SetSlotsAvalible(crowCharacterptr->GetSlotsAvalible() - 1);
}