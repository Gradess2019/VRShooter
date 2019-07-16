// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class SHOOTER_API AWeapon : public AActor
{
	GENERATED_BODY()

public:

	UFUNCTION()
	virtual void Fire();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Weapon settings")
	UStaticMeshComponent* mesh;

};
