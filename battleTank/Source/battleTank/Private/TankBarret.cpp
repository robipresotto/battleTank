// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankBarret.h"


void UTankBarret::elevate(float relativeSpeed) {
    
    // Move the barrel the right amount this frame
    // Given a max elevation speed, and the frame time
    
    auto time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("%f - Barrel->elevate called at speed: %f"), time, relativeSpeed);

}
