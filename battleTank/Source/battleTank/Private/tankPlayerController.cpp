// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "tankPlayerController.h"

void AtankPlayerController::BeginPlay() {
    Super::BeginPlay();
    
    auto controlledTank = GetControlledTank();
    
    if (!controlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not possesing a tank"));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possesing: %s"), *controlledTank->GetName());
    }
    
}

void AtankPlayerController::Tick( float DeltaTime ) {
    Super::Tick( DeltaTime );
    
    AimTowardsCrosshair();
    
    UE_LOG(LogTemp, Warning, TEXT("Player controller ticking..."));
}

ATank* AtankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

void AtankPlayerController::AimTowardsCrosshair() {
    
    if (!GetControlledTank()) { return ; }
    
    FVector hitLocation; //out parameter
    
    if (GetSightRayHitLocation(hitLocation)) { // Has "side-effect", is going to line trace
    
        UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *hitLocation.ToString());
        
    }
    
    
}

// Get world location if linetrace through crosshair, true if hits the landscape
bool AtankPlayerController::GetSightRayHitLocation(FVector &hitLocation) const {
 
    // Find the crosshair position
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
    
    UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
    
    return true;
    
}
