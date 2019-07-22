// Copyright EnterVR 2019


#include "Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "Target.h"

ABullet::ABullet()
{
	InitializeStaticMeshComponent();
	InitializeRootComponent();

	InitialLifeSpan = 2.f;
	impulsePower = 1500.f;
}

void ABullet::InitializeStaticMeshComponent()
{
	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("BulletBody");
	staticMeshComponent->SetSimulatePhysics(true);
	staticMeshComponent->SetEnableGravity(false);
	staticMeshComponent->SetCollisionProfileName("Bullet");
	staticMeshComponent->OnComponentHit.AddDynamic(this, &ABullet::OnComponentHit);
}

void ABullet::InitializeRootComponent()
{
	RootComponent = Cast<USceneComponent>(staticMeshComponent);
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();

	FVector impulse = GetActorForwardVector() * impulsePower;
	staticMeshComponent->AddImpulse(impulse);
}

void ABullet::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	FVector NormalImpulse, const FHitResult& Hit)
{
	ITarget* target = Cast<ITarget>(OtherActor);

	if (target != nullptr)
	{
		target->Execute_DecreaseDurability(OtherActor, damage);
	}

	this->Destroy();
}


