// Copyright EnterVR 2019


#include "Pistol.h"
#include "ConstructorHelpers.h"

#define LOG(Message) UE_LOG(WeaponLog, Log, TEXT("Pistol: %s"), TEXT(Message))

UPistol::UPistol() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset(TEXT("StaticMesh'/Game/Pistol_StaticMesh.Pistol_StaticMesh'"));
	UStaticMesh* newStaticMesh = staticMeshAsset.Object;

	if (staticMeshAsset.Succeeded())
	{
		SetStaticMesh(newStaticMesh);
	} 
}

void UPistol::OnFire_Implementation()
{
	LOG("Fire");
}

void UPistol::OnStopFire_Implementation()
{
	LOG("Stop fire");
}
