// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "GameFramework/PlayerController.h"
#include "tankPlayerController.generated.h" // Must be the last include

class ATank;
class UtankAimingComponent;

/**
 *  Responsible for helping the player aim.
 */

UCLASS()
class BATTLETANK_API AtankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
    
    UFUNCTION(BlueprintCallable, Category = "Setup")
    ATank* GetControlledTank() const;
    
    UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
    void FoundAimingComponent(UtankAimingComponent *aimCompRef);
    
private:

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    
    // Start the tank moving the barrel so that a shot whould it where the crosshair intersects the world
    void AimTowardsCrosshair();
    
    // Return an OUT parameter, true if hit landscape
    bool GetSightRayHitLocation(FVector &hitLocation) const;
    
    bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;
    
    bool GetLookVectorHitLocation(FVector lookDirection, FVector &hitLocation) const;
    
    UPROPERTY(EditDefaultsOnly)
    float crossHairXLocation = 0.5f;
    UPROPERTY(EditDefaultsOnly)
    float crossHairYLocation = 0.33333f;
    UPROPERTY(EditDefaultsOnly)
    float lineTraceRange = 1000000; // in cm
};
