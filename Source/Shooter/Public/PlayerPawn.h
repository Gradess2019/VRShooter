// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Weapon.h"
#include "PlayerPawn.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(PlayerPawnLog, Log, All);

UCLASS()
class SHOOTER_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:

	APlayerPawn(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn settings")
	USceneComponent* VROrigin;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Pawn settings")
	class UCameraComponent* cameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn settings")
	class UMotionControllerComponent* leftController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn settings")
	class UMotionControllerComponent* rightController;

private:

	void InitializeBaseComponents();

	template<class T>
	T* CreateComponent(const FName& COMPONENT_NAME, USceneComponent* parent);

	UFUNCTION()
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void BeginPlay() override;

	void FireLeft();
	
	UFUNCTION()
	void FireRight();

};
