// Fill out your copyright notice in the Description page of Project Settings.

#include "CorpseInteractable.h"
#include "Public/CrowCharacter.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

void ACorpseInteractable::BeginPlay()
{
	Super::BeginPlay();
	remainingFood = UKismetMathLibrary::RandomFloatInRange(minFuel, maxFuel);
	foodCap = remainingFood;
}

void ACorpseInteractable::Tick(float DeltaSeconds)
{


	// Feeding crows in tick
	if (eatingCrows.Num() == 0)
	{
		remainingFood += foodRestorePerTick * DeltaSeconds;
		return;
	}
	for (ACrowCharacter* crow : eatingCrows)
	{
		float foodEaten = DeltaSeconds * foodEatenPerTick;
		if (remainingFood <= 0)
		{
			// Force crow away from feeding
			crow->ForceFeedingFinish();
			eatingCrows.Remove(crow);
			return;
		}
		else
		{
			remainingFood -= foodEaten;
			crow->SetCurrentSatedLevel(crow->GetCurrentSatedLevel() + foodEaten);
		}
		
	}
}
void ACorpseInteractable::OnInteraction(ACrowCharacter* crowCharacterptr)
{
	
	if(eatingCrows.Contains(crowCharacterptr)) return;
	eatingCrows.Add(crowCharacterptr);
	crowCharacterptr->SetEatenCorpse(this);
	// we should disable his controls for as long as he keeps eating, meaning release of Right mouse button
	crowCharacterptr->ForceFeedingStart();

}
void ACorpseInteractable::OnButtonReleased(ACrowCharacter* crowCharacterptr)
{

	crowCharacterptr->ForceFeedingFinish();
	eatingCrows.Remove(crowCharacterptr);
	UE_LOG(LogTemp, Warning, TEXT("On Button Released:: Feeding finished!"));
}

