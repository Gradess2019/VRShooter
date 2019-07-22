// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Target.h"
#include "NPCPawn.generated.h"

UCLASS()
class SHOOTER_API ANPCPawn : public APawn, public ITarget
{
	GENERATED_BODY()

public:

	void DecreaseDurability_Implementation(const float& DECREMENT) override;

	ETargetType GetType_Implementation() const override;

};
