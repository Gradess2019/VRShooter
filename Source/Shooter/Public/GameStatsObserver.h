// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameStats.h"
#include "GameStatsObserver.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UGameStatsObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * Provides interface of an observer of game stats
 */
class SHOOTER_API IGameStatsObserver
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameStatsObserver")
	void Update(const TScriptInterface<class IGameStats>& statsSubject);
};
