// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CrowCharacter.generated.h"

UCLASS()
class WINTERJAM19_API ACrowCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACrowCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	int GetSlotsAvalible();
	void SetSlotsAvalible(int amountOfSpace);
protected:
	UPROPERTY(BlueprintReadWrite, Category = "Hunger")
		float currentSatedLevel = 150.0f;
	//Sated Cap
	UPROPERTY(EditDefaultsOnly, Category = "Hunger")
		float maxSatedLevel = 200.0f;
	//How seated the character currently is
	UPROPERTY(BlueprintReadWrite, Category = "Hunger")
		bool isEating = false;
private:
	// Tracks amount of free space for shiny objects
	int slotsAvaliable = 1;


};
