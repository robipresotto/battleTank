// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "tankPlayerController.h"
#include "tankAimingComponent.h"

void AtankPlayerController::BeginPlay() {
    Super::BeginPlay();
    
    auto aimingComponent = GetPawn()->FindComponentByClass<UtankAimingComponent>();
    
    if (!ensure(aimingComponent)) { return; }
    FoundAimingComponent(aimingComponent);
    
}

void AtankPlayerController::Tick( float DeltaTime ) {
    Super::Tick( DeltaTime );
    
    AimTowardsCrosshair();
    
}

void AtankPlayerController::AimTowardsCrosshair() {
    
    if (!GetPawn()) { return; } // e.g. if not possessing
    auto aimingComponent = GetPawn()->FindComponentByClass<UtankAimingComponent>();
    
    if (!ensure(aimingComponent)) { return; }
    
    FVector hitLocation; //out parameter
    
    if (GetSightRayHitLocation(hitLocation)) { // Has "side-effect", is going to line trace
        aimingComponent->AimAt(hitLocation);
    }
    
    
}

// Get world location if linetrace through crosshair, true if hits the landscape
bool AtankPlayerController::GetSightRayHitLocation(FVector &hitLocation) const {
 
    // Find the crosshair position in pixel coordinates
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto screenLocation = FVector2D(ViewportSizeX * crossHairXLocation, ViewportSizeY * crossHairYLocation);
    
    // "De-project" the screen position of the crosshair to a world direction
    FVector lookDirection;
    if (GetLookDirection(screenLocation, lookDirection)) {
        
        // Line-trace along that LookDirection, and see what we hit (up to max range)
        return GetLookVectorHitLocation(lookDirection, hitLocation);
    }
    
    return false;
    
}

bool AtankPlayerController::GetLookDirection(FVector2D screenLocation, FVector &lookDirection) const {
    
    FVector lookLocation;
    return DeprojectScreenPositionToWorld(
      screenLocation.X,
      screenLocation.Y,
      lookLocation,
      lookDirection
    );

}

bool AtankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector &hitLocation) const {
    
    FHitResult hitResult;
    auto startLocation = PlayerCameraManager->GetCameraLocation();
    auto endLocation = startLocation + ( lookDirection * lineTraceRange );
    
    if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility)) {
        hitLocation = hitResult.Location;
        return true;
    } else {
        hitLocation = FVector(0);
        return false;
    }
    
}
