// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "WeaponFactory.h"
#include "DefaultWeaponFactory.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class SHOOTER_API UDefaultWeaponFactory : public UWeaponFactory
{
	GENERATED_BODY()

public:

	UClass* CreatePistol() override;
};
