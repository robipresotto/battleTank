// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::initialise(UTankTrack *leftTrackToSet, UTankTrack *rightTrackToSet) {
    
    if (!ensure(leftTrackToSet && rightTrackToSet)) { return; }

    leftTrack = leftTrackToSet;
    rightTrack = rightTrackToSet;
    
}

void UTankMovementComponent::intendMoveForward(float Throw) {
    
    if (!ensure(leftTrack && rightTrack)) { return; }

    leftTrack->SetThrottle(Throw);
    rightTrack->SetThrottle(Throw);
    
}

void UTankMovementComponent::intendTurnRight(float Throw) {
    
    if (!ensure(leftTrack && rightTrack)) { return; }

    leftTrack->SetThrottle(Throw);
    rightTrack->SetThrottle(-Throw);
    
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {

    // No need to call super as we're replacing the functionality here
    
    auto tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto aiForwardIntention = MoveVelocity.GetSafeNormal();
    auto forwardThrow = FVector::DotProduct(tankForward, aiForwardIntention);
    auto rightThrow = FVector::CrossProduct(tankForward, aiForwardIntention).Z;

    intendMoveForward(forwardThrow);
    intendTurnRight(rightThrow);
    
}
