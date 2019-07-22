// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Pistol.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTER_API UPistol : public UWeapon
{
	GENERATED_BODY()

public:
	UPistol();

	void OnFire_Implementation() override;
	void OnStopFire_Implementation() override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon settings")
	TSubclassOf<ABullet> bulletClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon settings")
	float fireRate;

	void SpawnBullet();

private:

	FTimerHandle fireTimer;
};
