// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameStats.generated.h"

class IGameStatsObserver;
// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UGameStats : public UInterface
{
	GENERATED_BODY()
};

/**
 * Presents object as game stats container
 */
class SHOOTER_API IGameStats
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, Category = "GameStats")
	void AddObserver(const TScriptInterface<IGameStatsObserver>& newObserver);

	UFUNCTION(BlueprintNativeEvent, Category = "GameStats")
	void AddScore(const float& SCORE);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "GameStats")
	float GetScore() const;

protected:

	UFUNCTION(BlueprintNativeEvent, Category = "GameStats")
	void UpdateTime();

	UFUNCTION(BlueprintNativeEvent, Category = "GameStats")
	void Notify();

};
