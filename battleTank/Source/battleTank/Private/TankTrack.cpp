// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack() {
 
    PrimaryComponentTick.bCanEverTick = true;
    
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
    
    auto slippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
    
    // Work-out the required acceleration this frame to correct
    auto correctionAcceleration = -slippageSpeed / DeltaTime * GetRightVector();
    
    // Calculate and apply sideways (F = m a)
    auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    auto correctionForce = (tankRoot->GetMass() * correctionAcceleration) / 2; // Two tracks
    tankRoot->AddForce(correctionForce);
    
}

void UTankTrack::SetThrottle(float throttle) {
        
    auto forceApplied = GetForwardVector() * throttle * trackMaxDrivingForce;
    auto forceLocation = GetComponentLocation();
    auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied, forceLocation);
    
}
