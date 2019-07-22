// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameStats.h"
#include "GameStatsObserver.h"
#include "StatsComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(StatsComponentLog, Log, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTER_API UStatsComponent : public UActorComponent, public IGameStats
{
	GENERATED_BODY()

public:

	void AddObserver_Implementation(const TScriptInterface<IGameStatsObserver>& newObserver) override;
	void AddScore_Implementation(const float& SCORE) override;
	float GetScore_Implementation() const override;

private:

	float score;
	
	int gameTime;
	FTimerHandle gameTimerHandle;

	TSet<TScriptInterface<IGameStatsObserver> > observers;

	void BeginPlay() override;

	void UpdateTime_Implementation() override;
	void Notify_Implementation() override;
};
