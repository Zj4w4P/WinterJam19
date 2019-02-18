// Fill out your copyright notice in the Description page of Project Settings.

#include "LadyCrowNest.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Public/InteractionSystem/ShinyInteractable.h"

// Sets default values
ALadyCrowNest::ALadyCrowNest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	triggerRange = CreateDefaultSubobject<UBoxComponent>("Collision Box");
}

// Called when the game starts or when spawned
void ALadyCrowNest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALadyCrowNest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void  ALadyCrowNest::forceDrop(AActor* carriedItem)
{
	AShinyInteractable* interactableRef = Cast<AShinyInteractable>(carriedItem);
	if (!interactableRef)
	{
		UE_LOG(LogTemp, Error, TEXT("ALadyCrowNest :: Unknown overlapped item!"));
		return;
	}
	// Object is given to crow mommy, no point in giving it
	interactableRef->bIsActive = false;
	interactableRef->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	interactableRef->SetActorEnableCollision(true);
	interactableRef->OnItemDrop.Broadcast();
	UE_LOG(LogTemp, Error, TEXT("ALadyCrowNest :: Proper overlapped item!"));
	
}

