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
	if (eatingCrows.Num() == 0) return;
	for ( ACrowCharacter* crow : eatingCrows)
	{
		
	}
}


