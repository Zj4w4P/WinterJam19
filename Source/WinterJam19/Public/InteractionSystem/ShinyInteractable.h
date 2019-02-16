// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionSystem/BaseInteractable.h"
#include "ShinyInteractable.generated.h"

/**
 * 
 */
UCLASS()
class WINTERJAM19_API AShinyInteractable : public ABaseInteractable
{
	GENERATED_BODY()
	
		virtual void OnInteraction(ACrowCharacter* crowCharacterptr) override;
	
	private:
		ACrowCharacter* owningCrow = nullptr;
};
