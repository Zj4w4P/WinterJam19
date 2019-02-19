// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CrowPlayerState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScoreChanged);
/**
 * 
 */
UCLASS()
class WINTERJAM19_API ACrowPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
		FOnScoreChanged onScoreChanged;
protected:
	UPROPERTY(BlueprintReadOnly)
	int currentScore = 0;
	UPROPERTY(BlueprintReadOnly)
	int scoreCap = 0;
};
