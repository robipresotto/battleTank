// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "tankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UtankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UtankAimingComponent();
    
    void setBarrelReference(UStaticMeshComponent *barrelToSet);
    
    // TODO add SetTurretRef
    
    void AimAt(FVector hitLocation, float launchSpeed);
	
private:
    
    UStaticMeshComponent *barrel = nullptr;
    void MoveBarrelTowards(FVector AimDirection);
    
};
