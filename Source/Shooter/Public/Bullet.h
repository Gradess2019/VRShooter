// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class SHOOTER_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	ABullet();

	UFUNCTION()
	void BeginPlay() override;

protected:

	UPROPERTY(EditDefaultsOnly, )

};
