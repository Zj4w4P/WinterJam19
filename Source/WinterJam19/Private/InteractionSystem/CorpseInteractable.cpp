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
	UE_LOG(LogTemp, Warning, TEXT("Wellp it works sort of?"));
	if(eatingCrows.Contains(crowCharacterptr)) return;
	eatingCrows.Add(crowCharacterptr);
	// we should disable his controls for as long as he keeps eating, meaning release of Right mouse button
	UE_LOG(LogTemp, Warning, TEXT("Wellp it works sort of 2?"));

}


