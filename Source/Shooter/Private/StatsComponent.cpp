// Copyright EnterVR 2019


#include "StatsComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "GameStatsObserver.h"

DEFINE_LOG_CATEGORY(StatsComponentLog);
#define LOG(Message) UE_LOG(StatsComponentLog, Log, TEXT(Message))

void UStatsComponent::AddObserver_Implementation(const TScriptInterface<IGameStatsObserver>& newObserver)
{
	observers.Add(newObserver);
	LOG("New observer was attached");
}

void UStatsComponent::AddScore_Implementation(const float& SCORE)
{
	score += SCORE;
	LOG("Score added");
}

float UStatsComponent::GetScore_Implementation() const
{
	return score;
}

void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(gameTimerHandle, this, &UStatsComponent::UpdateTime, 1.f, true, true);
	LOG("Timer was set");
}

void UStatsComponent::UpdateTime_Implementation()
{
	gameTime++;
	Notify();
	LOG("Update Time");
}

void UStatsComponent::Notify_Implementation()
{
	for (const TScriptInterface<IGameStatsObserver>& observer : observers)
	{
		observer->Execute_Update(observer.GetObject(), this);
	}
	LOG("Observers were notified");
}
