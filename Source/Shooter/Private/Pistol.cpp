// Copyright EnterVR 2019


#include "Pistol.h"
#include "ConstructorHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TimerManager.h"

#define LOG(Message) UE_LOG(WeaponLog, Log, TEXT("Pistol: %s"), TEXT(Message))
#define WARNING(Message) UE_LOG(WeaponLog, Warning, TEXT("Pistol: %s"), TEXT(Message))
#define ERROR(Message) UE_LOG(WeaponLog, Error, TEXT("Pistol: %s"), TEXT(Message))

UPistol::UPistol() : Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset(TEXT("StaticMesh'/Game/Meshes/SM_Pistol.SM_Pistol'"));

	if (staticMeshAsset.Succeeded())
	{
		Super::SetStaticMesh(staticMeshAsset.Object);
	} else
	{
		ERROR("Couldn't load static mesh");
	}

	fireRate = 0.075f;
}

void UPistol::OnFire_Implementation()
{
	if (bulletClass.Get() == nullptr) return;

	GetWorld()->GetTimerManager().SetTimer(fireTimer, this, &UPistol::SpawnBullet, fireRate, true, false);
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
	GetWorld()->GetTimerManager().ClearTimer(fireTimer);
	LOG("Stop fire");
}