// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Weapon.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SHOOTER_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PostInitializeComponents() override;

private:
	
	void FireLeft();
	void FireRight();

};
