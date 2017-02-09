// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */

UCLASS( meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    
    // Sets a throttle between -1 and +1
    UFUNCTION(BlueprintCallable, Category = Input)
    void SetThrottle(float throttle);
	
};
