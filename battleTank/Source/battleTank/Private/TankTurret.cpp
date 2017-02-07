// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankTurret.h"

void UTankTurret::rotate(float relativeSpeed) {
    
    // Move the turret the right amount this frame
    
    relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, +1);
    auto RotationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    
    auto rotation = RelativeRotation.Yaw + RotationChange;

    SetRelativeRotation(FRotator(0, rotation, 0));
    
}
