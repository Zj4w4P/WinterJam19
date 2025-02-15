// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LadyCrowNest.generated.h"

class UBoxComponent;

UCLASS()
class WINTERJAM19_API ALadyCrowNest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALadyCrowNest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "Collision")
		UBoxComponent* triggerRange;
	UFUNCTION(BlueprintCallable)
		void forceDrop(AActor* carriedItem);
};
