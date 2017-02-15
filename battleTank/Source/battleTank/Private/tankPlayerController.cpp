// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "Tank.h"
#include "tankPlayerController.h"
#include "tankAimingComponent.h"

void AtankPlayerController::BeginPlay() {
    Super::BeginPlay();
    
    auto aimingComponent = GetControlledTank()->FindComponentByClass<UtankAimingComponent>();
    
    if (aimingComponent) {
        FoundAimingComponent(aimingComponent);
    }
    
}

void AtankPlayerController::Tick( float DeltaTime ) {
    Super::Tick( DeltaTime );
    
    AimTowardsCrosshair();
    
}

ATank* AtankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

void AtankPlayerController::AimTowardsCrosshair() {
    
    if (!GetControlledTank()) { return ; }
    
    FVector hitLocation; //out parameter
    
    if (GetSightRayHitLocation(hitLocation)) { // Has "side-effect", is going to line trace
        GetControlledTank()->AimAt(hitLocation);
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
        GetLookVectorHitLocation(lookDirection, hitLocation);
        
        // GetLookVectorHitLocation()
        // Make a LineTraceRange parameter = 10km
        // Line-trace out to this distance in LookDirection
        // Trace by ECC_Visibility channel (if you can see it)
        // Return true if hits, and HitLocation as OUT
        // Return false if nothing is hit
        // Log-out to see what you're hitting
        
//        UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *lookDirection.ToString());
    }
    
    
    return true;
    
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
