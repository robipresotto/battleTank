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
    
    // Get world location if linetrace through crosshair
    // if it hits the landscape
    
    
}
