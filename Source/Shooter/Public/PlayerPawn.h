// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(PlayerPawnLog, Log, All);

UCLASS()
class SHOOTER_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:

	APlayerPawn(const FObjectInitializer& ObjectInitializer);

protected:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Pawn settings")
	USceneComponent* VROrigin;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly,Category = "Pawn settings")
	class UCameraComponent* cameraComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Pawn settings")
	class UMotionControllerComponent* leftController;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Pawn settings")
	class UMotionControllerComponent* rightController;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Pawn settings")
	class UWeapon* rightWeapon;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Pawn settings")
	UWeapon* leftWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pawn settings")
	TSubclassOf<class UWeaponFactory> weaponFactoryClass;

private:

	UPROPERTY()
	UWeaponFactory* weaponFactory;
	
	void InitializeBaseComponents();

	template<class T>
	T* CreateComponent(const FName& COMPONENT_NAME, USceneComponent* parent);

	USceneComponent* CreateComponent(const FName& COMPONENT_NAME, UClass* componentClass, USceneComponent* parent);
	USceneComponent* CreateComponentAtRuntime(const FName& COMPONENT_NAME, UClass* componentClass, USceneComponent* parent);

	void CheckFactoryClass();
	void InitializeFactory();
	void InitializeWeapon();

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	FName GetPropertyName(FPropertyChangedEvent& PropertyChangedEvent);
	bool IsWeaponFactoryClassProperty(const FName& PROPERTY_NAME) const;

	void ChangeFactory();
	void ChangeWeapon();

	UFUNCTION()
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void BeginPlay() override;

	void FireLeft();
	
	UFUNCTION()
	void FireRight();

};
