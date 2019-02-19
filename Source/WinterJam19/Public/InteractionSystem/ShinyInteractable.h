// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractionSystem/BaseInteractable.h"
#include "ShinyInteractable.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEnablePhysicsDelegate);
/**
 * 
 */
UCLASS()
class WINTERJAM19_API AShinyInteractable : public ABaseInteractable
{
	GENERATED_BODY()
	
	protected:
		virtual void BeginPlay() override;
	private:
		virtual void OnInteraction(ACrowCharacter* crowCharacterptr) override;
		ACrowCharacter* owningCrow = nullptr;
		UPROPERTY(EditDefaultsOnly, Category = "Points")
			int minPointsGiven = 100;
		UPROPERTY(EditDefaultsOnly, Category = "Points")
			int maxPointsGiven = 200;
	
	public:
		UPROPERTY(BLueprintReadWrite, Category = "Pickup")
		bool bIsActive = true;
		UPROPERTY(BlueprintAssignable)
			FEnablePhysicsDelegate OnItemDrop;
		void Drop();
		UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Points")
			int pointsGiven = 100;
};
