// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float throttle) {
    
    auto name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("tank %s track throttle %f"), *name, throttle);
    
    // TODO clamp actual throttle value so player can't  over-drive
    auto forceApplied = GetForwardVector() * throttle * trackMaxDrivingForce;
    auto forceLocation = GetComponentLocation();
    auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied, forceLocation);
    
}
