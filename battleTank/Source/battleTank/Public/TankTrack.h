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
    UFUNCTION(BlueprintCallable, Category = "Input")
    void SetThrottle(float throttle);

    // Max force per track in newtons (force = mass * acceleration) kg/s
    UPROPERTY(EditDefaultsOnly)
    float trackMaxDrivingForce = 400000; // assume 40 tonne tank and 1g accelleration
    
private:
    
    UTankTrack();
    
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

};
