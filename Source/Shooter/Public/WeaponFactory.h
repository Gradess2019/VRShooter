// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeaponFactory.generated.h"

/**
 * Base weapon factory class
 */
UCLASS(Blueprintable, BlueprintType, Abstract)
class SHOOTER_API UWeaponFactory : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Weapon Factory", meta = (KeyWords = "Weapon Factory Create Pistol"))
	virtual UClass* GetPistolClass();

	UFUNCTION(BlueprintCallable, Category = "Weapon Factory", meta = (KeyWords = "Weapon Factory Create Shield"))
	virtual UClass* GetShieldClass();

	UFUNCTION(BlueprintCallable, Category = "Weapon Factory", meta = (KeyWords = "Weapon Factory Create Whip"))
	virtual UClass* GetWhipClass();

};
