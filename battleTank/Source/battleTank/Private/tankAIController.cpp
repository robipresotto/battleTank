// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "tankAIController.h"

void AtankAIController::BeginPlay() {
    Super::BeginPlay();
    
    auto playerTank = GetPlayerTank();
    
    if (!playerTank) {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController not controlling player tank"));
    } else {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController controlling player %s tank"), *playerTank->GetName());
    }
    
}

ATank* AtankAIController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

ATank* AtankAIController::GetPlayerTank() const {
    
    auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

    if (!playerPawn) { return nullptr; } else {
        return Cast<ATank>(playerPawn);
    }
    
}
