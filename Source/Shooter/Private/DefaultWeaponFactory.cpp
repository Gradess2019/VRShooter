// Copyright EnterVR 2019


#include "DefaultWeaponFactory.h"
#include "Pistol.h"

UClass* UDefaultWeaponFactory::GetPistolClass()
{
	return UPistol::StaticClass();
}
