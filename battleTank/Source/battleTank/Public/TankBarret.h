// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarret.generated.h"

/**
 * 
 */
UCLASS( meta=(BlueprintSpawnableComponent), hidecategories = ("Collision") )
class BATTLETANK_API UTankBarret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    void elevate(float degreesPerSecond);
	
private:
    UPROPERTY(EditAnywhere, Category = Setup)
    float maxDegreesPerSecond = 20; // sensible default
    UPROPERTY(EditAnywhere, Category = Setup)
    float maxElevationDegrees = 40;
    UPROPERTY(EditAnywhere, Category = Setup)
    float minElevationDegrees = 0;
};
