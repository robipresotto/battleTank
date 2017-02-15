// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "tankAimingComponent.generated.h"

class UTankBarret;
class UTankTurret;

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
    
    void AimAt(FVector hitLocation, float launchSpeed);
    
protected:
    // accessed by tankPlayerController
    UPROPERTY(BlueprintReadOnly, Category = "State")
    EFiringState tankFireState = EFiringState::Locked;
	
private:
    
    UtankAimingComponent();

    UTankBarret *barrel = nullptr;
    UTankTurret *turret = nullptr;
    void MoveBarrelTowards(FVector AimDirection);
    
};
