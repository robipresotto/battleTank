// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 *  Fly-by-wire controller
 *  Responsible for driving the tank tracks
 */

UCLASS( ClassGroup = (Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void initialise(UTankTrack *leftTrackToSet, UTankTrack *rightTrackToSet);
    
    UFUNCTION(BlueprintCallable, Category = Input)
    void intendMoveForward(float Throw);
    
    UFUNCTION(BlueprintCallable, Category = Input)
    void intendTurnRight(float Throw);

private:
    
    UTankTrack *leftTrack = nullptr;
    UTankTrack *rightTrack = nullptr;
    
};
