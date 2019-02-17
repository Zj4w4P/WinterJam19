// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "MistressCrowNest.generated.h"

class AShinyInteractable;

/**
 * 
 */
UCLASS()
class WINTERJAM19_API AMistressCrowNest : public ATriggerVolume
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Pickup Drop")
		void ForcePickupDrop(AShinyInteractable* droppedItem);
	
	
};
