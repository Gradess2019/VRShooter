// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "Shooter.h"
#include "UObject/Interface.h"
#include "Target.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UTarget : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface of an object that can be considered as a target for AI
 */
class SHOOTER_API ITarget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Target")
	ETargetType GetType() const;
};
