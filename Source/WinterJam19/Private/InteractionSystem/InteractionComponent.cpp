// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionComponent.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Engine/World.h"


// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractionComponent::RaycastInteract(FVector LookDirection)
{
	// TODO, we probably want to change it to head socket or something like this, root is kinda iffy
	FVector startPos = this->GetOwner()->GetActorLocation();
	//
	FVector endPos = startPos + LookDirection * castingRange;
	FHitResult traceHitResult;
	FCollisionObjectQueryParams queryParams = FCollisionObjectQueryParams();
	DrawDebugLine(GetWorld(), startPos, endPos, FColor::Orange, true, 8, 2.0F);
	//this->GetWorld()->LineTraceSingleByObjectType(traceHitResult, startPos, endPos,queryParams);

}