// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "tankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API AtankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
    
    ATank* GetControlledTank() const;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    
    // Start the tank moving the barrel so that a shot whould it where the crosshair intersects the world
    void AimTowardsCrosshair();
    
};
