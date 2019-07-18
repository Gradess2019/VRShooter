// Copyright EnterVR 2019


#include "Pistol.h"
#include "ConstructorHelpers.h"
#include "Kismet/KismetSystemLibrary.h"

#define LOG(Message) UE_LOG(WeaponLog, Log, TEXT("Pistol: %s"), TEXT(Message))
#define WARNING(Message) UE_LOG(WeaponLog, Warning, TEXT("Pistol: %s"), TEXT(Message))
#define ERROR(Message) UE_LOG(WeaponLog, Error, TEXT("Pistol: %s"), TEXT(Message))

UPistol::UPistol() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset(TEXT("StaticMesh'/Game/Pistol_StaticMesh.Pistol_StaticMesh'"));

	if (staticMeshAsset.Succeeded())
	{
		Super::SetStaticMesh(staticMeshAsset.Object);
	} else
	{
		ERROR("Couldn't load static mesh");
	}

	UE_LOG(WeaponLog, Warning, TEXT("Pistol: %s"), *UKismetSystemLibrary::GetDisplayName(bulletClass.Get()));
}

void UPistol::OnFire_Implementation()
{
	if (bulletClass.Get() == nullptr) return;

	SpawnBullet();
	LOG("Fire");
}

void UPistol::SpawnBullet()
{
	FActorSpawnParameters spawnParameters;
	spawnParameters.Owner = this->GetOwner();
	spawnParameters.Instigator = this->GetOwner()->Instigator;
	FTransform bulletTransform = GetComponentTransform();
	AActor* bullet = GetWorld()->SpawnActor<AActor>(bulletClass, GetComponentLocation(), GetComponentRotation(), spawnParameters);
}

void UPistol::OnStopFire_Implementation()
{
	LOG("Stop fire");
}