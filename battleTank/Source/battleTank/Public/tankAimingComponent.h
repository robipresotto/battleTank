// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "tankAimingComponent.generated.h"

class UTankBarret;
class UTankTurret;

// Hold barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UtankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

    UtankAimingComponent();
    
    void setBarrelReference(UTankBarret *barrelToSet);
    void setTurretReference(UTankTurret *turretToSet);
    
    void AimAt(FVector hitLocation, float launchSpeed);
	
private:
    
    UTankBarret *barrel = nullptr;
    UTankTurret *turret = nullptr;
    void MoveBarrelTowards(FVector AimDirection);
    void RotateTurret(FVector AimDegrees);
    
};
