// Copyright EnterVR 2019


#include "Bullet.h"

ABullet::ABullet()
{
	class UStaticMeshComponent* staticMesh = CreateDefaultSubobject<UStaticMeshComponent>("BulletBody");
	
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();


}

