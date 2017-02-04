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

ATank* AtankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

