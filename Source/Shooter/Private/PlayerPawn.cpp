// Copyright EnterVR 2019

#include "Public/PlayerPawn.h"
#include "Components/InputComponent.h"

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//PlayerInputComponent->BindAction("FireLeft", EInputEvent::IE_Pressed, );
}

void APlayerPawn::PostInitializeComponents()
{
	
}

void APlayerPawn::FireLeft()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Left"));
}

void APlayerPawn::FireRight()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Right"));
}

