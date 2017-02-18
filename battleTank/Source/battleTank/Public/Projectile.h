// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	    
    void LaunchProjectile(float Speed);

private:
    
    UProjectileMovementComponent *projectileMovement = nullptr;
    
    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
    
    void OnTimerExpire();
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float DestroyDelay = 5.f;
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float projectileDamage = 20.f;
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent *collisionMesh = nullptr;
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UParticleSystemComponent *launchBlast = nullptr;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    UParticleSystemComponent *impactBlast = nullptr;
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    URadialForceComponent* explosionForce = nullptr;
    
};
