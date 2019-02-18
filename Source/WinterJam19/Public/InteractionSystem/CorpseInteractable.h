// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionSystem/BaseInteractable.h"
#include "CorpseInteractable.generated.h"

class CrowCharacter;
/**
 * 
 */
UCLASS()
class WINTERJAM19_API ACorpseInteractable : public ABaseInteractable
{
	GENERATED_BODY()
	
private: 
	UPROPERTY(EditDefaultsOnly, Category = "Fuel")
		float remainingFood = 200.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Fuel")
		float foodCap = 200.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Fuel")
		float minFuel = 150.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Fuel")
		float maxFuel = 300.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Fuel")
		float foodRestorePerTick = 0.05f;
	UPROPERTY(EditDefaultsOnly, Category = "Fuel")
		float foodEatenPerTick = 0.1f;

	
	 TArray<ACrowCharacter*> eatingCrows;

protected:
	virtual void BeginPlay() override;
	virtual void OnInteraction(ACrowCharacter* crowCharacterptr) override;

public:
	virtual void Tick(float DeltaTime) override;
};
