// Copyright EnterVR 2019

#include "Public/PlayerPawn.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "DefaultWeaponFactory.h"
#include "Weapon.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Pistol.h"

DEFINE_LOG_CATEGORY(PlayerPawnLog);
#define LOG(Message) UE_LOG(PlayerPawnLog, Log, TEXT(Message))
#define WARNING(Message) UE_LOG(PlayerPawnLog, Warning, TEXT(Message))

APlayerPawn::APlayerPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	WARNING("Construction");
	weaponFactoryClass = UDefaultWeaponFactory::StaticClass();
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	InitializeBaseComponents();
	InitializeFactory();
	InitializeWeapon();
}

void APlayerPawn::InitializeBaseComponents()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	VROrigin = CreateComponent<USceneComponent>("VROrigin", RootComponent);
	cameraComponent = CreateComponent<UCameraComponent>("VRCamera", VROrigin);
	leftController = CreateMotionControllerComponent("LeftMotionController", EControllerHand::Left);
	rightController = CreateMotionControllerComponent("RightMotionController", EControllerHand::Right);
}

template<class T>
T* APlayerPawn::CreateComponent(const FName& COMPONENT_NAME, USceneComponent* parent)
{
	checkf(parent, TEXT("Parent is null"));
	T* newComponent = CreateDefaultSubobject<T>(COMPONENT_NAME);
	newComponent->SetupAttachment(parent);
	return newComponent;
}

USceneComponent* APlayerPawn::CreateComponent(const FName& COMPONENT_NAME, UClass* componentClass, USceneComponent* parent)
{
	checkf(parent, TEXT("Parent is null"));
	USceneComponent* newComponent = Cast<USceneComponent>(CreateDefaultSubobject(
		COMPONENT_NAME,
		componentClass,
		componentClass,
		true,
		false,
		false
	));
	newComponent->SetupAttachment(parent);
	return newComponent;
}

USceneComponent* APlayerPawn::CreateComponentAtRuntime(const FName& COMPONENT_NAME, UClass* componentClass, USceneComponent* parent)
{
	checkf(parent, TEXT("Parent is null"));
	USceneComponent* newComponent = NewObject<USceneComponent>(this, componentClass);
	newComponent->SetupAttachment(parent);
	newComponent->RegisterComponent();
	return newComponent;
}

UMotionControllerComponent* APlayerPawn::CreateMotionControllerComponent(const FName& COMPONENT_NAME, const EControllerHand& SOURCE)
{
	UMotionControllerComponent* newMotionController = CreateComponent<UMotionControllerComponent>(COMPONENT_NAME, VROrigin);
	newMotionController->SetTrackingSource(SOURCE);
	return newMotionController;
}

void APlayerPawn::InitializeFactory()
{
	weaponFactory = Cast<UWeaponFactory>(CreateDefaultSubobject(
		"WeaponFactory", 
		weaponFactoryClass, 
		weaponFactoryClass,
		true, 
		false, 
		true
	));
}

void APlayerPawn::InitializeWeapon()
{
	leftWeapon = Cast<UWeapon>(CreateComponent("LeftWeapon", weaponFactory->GetPistolClass(), leftController));
	rightWeapon = Cast<UWeapon>(CreateComponent("RightWeapon", weaponFactory->GetPistolClass(), rightController));
}

void APlayerPawn::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	// TODO
	//const FName PROPERTY_NAME = GetPropertyName(PropertyChangedEvent);
	//if (IsWeaponFactoryClassProperty(PROPERTY_NAME))
	//{
	//	CheckFactoryClass();
	//	ChangeFactory();
	//	ChangeWeapon();
	//}
	//LOG("Property changed.");
}

FName APlayerPawn::GetPropertyName(FPropertyChangedEvent& PropertyChangedEvent)
{
	return IsValid(PropertyChangedEvent.Property) ? PropertyChangedEvent.GetPropertyName() : NAME_None;
}

bool APlayerPawn::IsWeaponFactoryClassProperty(const FName& PROPERTY_NAME) const
{
	return PROPERTY_NAME == GET_MEMBER_NAME_CHECKED(APlayerPawn, weaponFactoryClass);
}

void APlayerPawn::CheckFactoryClass()
{
	if (weaponFactoryClass)
	{
		LOG("Factory class is valid");
	}
	else
	{
		WARNING("Factory class is null! DefaultWeaponFactory will be used");
		weaponFactoryClass = UDefaultWeaponFactory::StaticClass();
	}
}

void APlayerPawn::ChangeFactory()
{
	weaponFactory = NewObject<UWeaponFactory>(this, weaponFactoryClass);
}

void APlayerPawn::ChangeWeapon()
{
	if (IsValid(leftWeapon))
	{
		leftWeapon->DestroyComponent();
		WARNING("Left Destroyed");
	}

	if (IsValid(rightWeapon))
	{
		rightWeapon->DestroyComponent();
		WARNING("Right Destroyed");
	}

	leftWeapon = Cast<UWeapon>(CreateComponentAtRuntime(FName("LeftWeapon"), weaponFactory->GetPistolClass(), leftController));
	rightWeapon = Cast<UWeapon>(CreateComponentAtRuntime(FName("RightWeapon"), weaponFactory->GetPistolClass(), rightController));
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("FireLeft", EInputEvent::IE_Pressed, this, &APlayerPawn::FireLeft);
	PlayerInputComponent->BindAction("FireRight", EInputEvent::IE_Pressed, this, &APlayerPawn::FireRight);
}

void APlayerPawn::BeginPlay()
{
	LOG("BeginPlay()");
	Super::BeginPlay();

	UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Floor);
}

void APlayerPawn::FireLeft()
{
	if (leftWeapon != nullptr)
	{
		leftWeapon->OnFire();
	}
	else
	{
		WARNING("leftWeapon is nullptr");
	}
}

void APlayerPawn::FireRight()
{
	if (rightWeapon != nullptr)
	{
		rightWeapon->OnFire();
	}
	else
	{
		WARNING("rightWeapon is nullptr");
	}
}
