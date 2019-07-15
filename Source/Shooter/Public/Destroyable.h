// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Destroyable.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UDestroyable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SHOOTER_API IDestroyable
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Destroyable")
	void DecreaseDurability(
		UPARAM(DisplayName = "Decrement") const float& DECREMENT
	);

};
