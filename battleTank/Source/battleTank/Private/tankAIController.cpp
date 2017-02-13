// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "Tank.h"
#include "tankAIController.h"

void AtankAIController::BeginPlay() {
    Super::BeginPlay();
    
    // ...
    
}

// Called every frame
void AtankAIController::Tick( float DeltaTime ) {
    Super::Tick( DeltaTime );
    
    auto playerTank = GetPlayerTank();
    auto controlledTank = GetControlledTank();
    
    if (playerTank) {
        
        // Move towards the player
        MoveToActor(playerTank, AcceptanceRadius);

        // Aim towards the player
        controlledTank->AimAt(playerTank->GetActorLocation());
        
        // Fire if ready
        controlledTank->Fire();
        
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
