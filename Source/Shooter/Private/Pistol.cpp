// Copyright EnterVR 2019


#include "Pistol.h"

#define LOG(Message) UE_LOG(WeaponLog, Log, TEXT("Pistol: %s"), TEXT(Message))

void UPistol::OnFire_Implementation()
{
	LOG("Fire");
}

void UPistol::OnStopFire_Implementation()
{
	LOG("Stop fire");
}
