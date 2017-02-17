// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "tankAimingComponent.generated.h"

class UTankBarret;
class UTankTurret;
class AProjectile;

// enum for aiming state
UENUM()
enum class EFiringState : uint8 {
    Locked,
    Aiming,
    Reloading
};

// Hold barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UtankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
    
    UFUNCTION(BlueprintCallable, Category = "Setup")
    void Initialise(UTankBarret *barrelToSet, UTankTurret *turretToSet);
    
    UFUNCTION(BlueprintCallable, Category = "Firing")
    void Fire();
    
    void AimAt(FVector hitLocation);
    
    EFiringState getFiringState() const;

protected:
    // accessed by tankPlayerController
    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringState firingState = EFiringState::Reloading;
	
private:
    
    UtankAimingComponent();
    
    virtual void BeginPlay() override;
    
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

    void MoveBarrelTowards(FVector AimDirection);

    bool isBarrelMoving();
    
    UTankBarret *barrel = nullptr;
    UTankTurret *turret = nullptr;
    
    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float launchSpeed = 4000;
    
    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float reloadTimeInSeconds = 3.f;
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<AProjectile> projectileBlueprint;
    
    double lastFireTime = 0;
    
    FVector aimDirection;
    
};
