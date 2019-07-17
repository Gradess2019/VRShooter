// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Pistol.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTER_API UPistol : public UWeapon
{
	GENERATED_BODY()

public:
	UPistol();

	void OnFire_Implementation() override;
	void OnStopFire_Implementation() override;
};
