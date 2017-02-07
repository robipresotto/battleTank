// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankBarret.h"


void UTankBarret::elevate(float relativeSpeed) {
    
    // Move the barrel the right amount this frame
    
    relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1, +1);
    auto elevationChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    
    auto rawNewElevation = RelativeRotation.Pitch + elevationChange;

    auto elevation = FMath::Clamp<float>(rawNewElevation, minElevationDegrees, maxElevationDegrees);
    
    SetRelativeRotation(FRotator(elevation, 0, 0));

}
