// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::initialise(UTankTrack *leftTrackToSet, UTankTrack *rightTrackToSet) {
    
    if (!leftTrackToSet || !rightTrackToSet) { return; }

    leftTrack = leftTrackToSet;
    rightTrack = rightTrackToSet;
    
}

void UTankMovementComponent::intendMoveForward(float Throw) {
        
    leftTrack->SetThrottle(Throw);
    rightTrack->SetThrottle(Throw);
    
}

void UTankMovementComponent::intendTurnRight(float Throw) {
    
    leftTrack->SetThrottle(Throw);
    rightTrack->SetThrottle(-Throw);
    
}
