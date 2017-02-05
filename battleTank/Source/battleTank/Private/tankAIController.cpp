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

// Called every frame
void AtankAIController::Tick( float DeltaTime ) {
    Super::Tick( DeltaTime );
    
    if (GetPlayerTank()) {
        //TODO: move towards the player
        
        // Aim towards the player
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
        
        // Fire if ready
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
