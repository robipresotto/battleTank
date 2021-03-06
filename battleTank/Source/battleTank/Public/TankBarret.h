// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarret.generated.h"

UCLASS( meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    // -1 is max downward speed, and +1 is max up movement
    void elevate(float relativeSpeed);
	
private:
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float maxDegreesPerSecond = 10; // sensible default
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float maxElevationDegrees = 40;
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float minElevationDegrees = 0;
};
