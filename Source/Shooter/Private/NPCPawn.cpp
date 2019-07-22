// Copyright EnterVR 2019


#include "NPCPawn.h"

void ANPCPawn::DecreaseDurability_Implementation(const float& DECREMENT)
{
	Destroy();
}

ETargetType ANPCPawn::GetType_Implementation() const
{
	return ETargetType::NPC;
}

