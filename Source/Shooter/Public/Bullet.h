// Copyright EnterVR 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

class FComponentHitSignature;

UCLASS()
class SHOOTER_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	ABullet();

	UFUNCTION()
	void BeginPlay() override;

protected:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Bullet settings")
	class UStaticMeshComponent* staticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet settings")
	float impulsePower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet settings")
	float damage;

private:

	UFUNCTION()
	void OnComponentHit( 
		UPrimitiveComponent* HitComponent, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		FVector NormalImpulse, 
		const FHitResult& Hit
	);

	void InitializeStaticMeshComponent();
	void InitializeRootComponent();


};
