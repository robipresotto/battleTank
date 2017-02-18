// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "tankAimingComponent.h"
#include "tankAIController.h"
#include "Tank.h"

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
    if (aimingComponent->getFiringState() == EFiringState::Locked) {
        aimingComponent->Fire();
    }
    
}

void AtankAIController::SetPawn(APawn* InPawn) {
    Super::SetPawn(InPawn);
    if (InPawn) {
        auto PossessedTank = Cast<ATank>(InPawn);
        if (!ensure(PossessedTank)) { return; }
        
        // Subscribe our local method to the tank's death event
        PossessedTank->OnDeath.AddUniqueDynamic(this, &AtankAIController::OnPossedTankDeath);
    }
}

void AtankAIController::OnPossedTankDeath() {

    if (!ensure(GetPawn())) { return; } // TODO remove if ok
    GetPawn()->DetachFromControllerPendingDestroy();

}
