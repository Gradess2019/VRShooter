// Copyright EnterVR 2019

#include "Public/PlayerPawn.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"


DEFINE_LOG_CATEGORY(PlayerPawnLog);
#define LOG(Message) UE_LOG(PlayerPawnLog, Log, TEXT(Message))

APlayerPawn::APlayerPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	InitializeBaseComponents();
}

void APlayerPawn::InitializeBaseComponents()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	VROrigin = CreateComponent<USceneComponent>("VROrigin", RootComponent);
	cameraComponent = CreateComponent<UCameraComponent>("VRCamera", VROrigin);
	leftController = CreateComponent<UMotionControllerComponent>("LeftMotionController", VROrigin);
	rightController = CreateComponent<UMotionControllerComponent>("RightMotionController", VROrigin);
}

template<class T>
T* APlayerPawn::CreateComponent(const FName& COMPONENT_NAME, USceneComponent* parent)
{
	checkf(parent, TEXT("Parent is null"));
	T* newComponent = CreateDefaultSubobject<T>(COMPONENT_NAME);
	newComponent->SetupAttachment(parent);
	return newComponent;
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
	Super::BeginPlay();

	UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Floor);
}

void APlayerPawn::FireLeft()
{
	LOG("Fire Left");
}

void APlayerPawn::FireRight()
{
	LOG("Fire Right");
}

