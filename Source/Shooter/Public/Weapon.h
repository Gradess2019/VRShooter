// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Weapon.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(WeaponLog, Log, All);

/**
 * Base weapon class
 */
UCLASS(Blueprintable, BlueprintType, Abstract)
class SHOOTER_API UWeapon : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Weapon settings", meta = (KeyWords = "On Fire Weapon Shoot Shot"))
	void OnFire();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Weapon settings", meta = (KeyWords = "On Fire Weapon Shoot Shot Stop"))
	void OnStopFire();

};
