// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float throttle) {
        
    auto forceApplied = GetForwardVector() * throttle * trackMaxDrivingForce;
    auto forceLocation = GetComponentLocation();
    auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied, forceLocation);
    
}
