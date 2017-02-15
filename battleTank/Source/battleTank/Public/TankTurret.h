

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

UCLASS( meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    // -1 is max downward speed, and +1 is max up movement
    void rotate(float relativeSpeed);
	
private:
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float maxDegreesPerSecond = 25; // sensible default
	
};
