// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootingComponent.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "ShinyInteractable.h"


// Sets default values for this component's properties
UShootingComponent::UShootingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UShootingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UShootingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UShootingComponent::GotShot(ACrowCharacter* crow, float damage) {
	UE_LOG(LogTemp, Warning, TEXT("GotShot"));
	if (crow->GetCurrentSatedLevel() >= damage)
		crow->SetCurrentSatedLevel(crow->GetCurrentSatedLevel() - damage);
	else
		crow->SetCurrentSatedLevel(0);
	AShinyInteractable* pickup = crow->GetPickup();
	if (pickup != NULL) {
		crow->SetSlotsAvalible(crow->GetSlotsAvalible() + 1);
		pickup->Drop();

	}
}

/*void UShootingComponent::RaycastShoot(FVector LookDirection)
{
	// TODO, we probably want to change it to head socket or something like this, root is kinda iffy
	FVector startPos = this->GetOwner()->GetActorLocation();
	FVector endPos = startPos + LookDirection * shootingRange;
	FHitResult traceHitResult;
	//FCollisionObjectQueryParams queryParams = FCollisionObjectQueryParams();

	DrawDebugLine(GetWorld(), startPos, endPos, FColor::Red, true, 8, 2.0F);
	if (this->GetWorld()->LineTraceSingleByChannel(traceHitResult, startPos, endPos, ECC_GameTraceChannel1))
	{
		UE_LOG(LogTemp, Warning, TEXT("UInteraction Component ::  Hit %s"), *(traceHitResult.Actor->GetName()));
		ACrowCharacter* victim = Cast<ACrowCharacter>(traceHitResult.Actor);
		if (!victim)
		{
			UE_LOG(LogTemp, Warning, TEXT("UInteraction Component :: Unknown Object Hit"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Kucze"));
			victim->GotShot(victim);
		}
	}


}
*/