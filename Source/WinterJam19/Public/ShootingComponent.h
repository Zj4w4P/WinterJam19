// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CrowCharacter.h"
#include "ShootingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WINTERJAM19_API UShootingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShootingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category = "Shooting")
		float defaultDamage = 25.0f;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "Shooting")
		void GotShot(ACrowCharacter* crow, float damage);
	/*UFUNCTION(BlueprintCallable, Category = "Shooting")
		void RaycastShoot(FVector LookDirection);
private:
	UPROPERTY(EditAnywhere, Category = "Raycasting")
		float shootingRange = 1000.0f;
		*/
		
	
};
