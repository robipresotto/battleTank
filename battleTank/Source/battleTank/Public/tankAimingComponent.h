// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "tankAimingComponent.generated.h"

class UTankBarret;

// Hold barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UtankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UtankAimingComponent();
    
    void setBarrelReference(UTankBarret *barrelToSet);
    
    // TODO: add SetTurretRef
    
    void AimAt(FVector hitLocation, float launchSpeed);
	
private:
    
    UTankBarret *barrel = nullptr;
    void MoveBarrelTowards(FVector AimDirection);
    
};
