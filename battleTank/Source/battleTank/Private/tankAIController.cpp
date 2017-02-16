// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "tankAimingComponent.h"
#include "tankAIController.h"

void AtankAIController::BeginPlay() {
    Super::BeginPlay();
    
    // ...
    
}

// Called every frame
void AtankAIController::Tick( float DeltaTime ) {
    Super::Tick( DeltaTime );
    
    auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    auto controlledTank = GetPawn();
    
    if (!ensure(playerTank && controlledTank)) { return ; }
        
    // Move towards the player
    MoveToActor(playerTank, AcceptanceRadius);

    // Aim towards the player
    auto aimingComponent = controlledTank->FindComponentByClass<UtankAimingComponent>();
    aimingComponent->AimAt(playerTank->GetActorLocation());
    
    // Fire if ready
    aimingComponent->Fire();
    
}
