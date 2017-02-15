

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankTurret;
class UTankBarret;
class UtankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
    
public:
    
    void AimAt(FVector hitLocation);
    
    UFUNCTION(BlueprintCallable, Category = "Firing")
    void Fire();
    
protected:
    
    UPROPERTY(BlueprintReadOnly)
    UtankAimingComponent *tankAimingComponent = nullptr;
    
    UPROPERTY(BlueprintReadOnly)
    UTankMovementComponent *tankMovementComponent = nullptr;

private:
    
	// Sets default values for this pawn's properties
	ATank();
    
    virtual void BeginPlay() override;
    
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float reloadTimeInSeconds = 3.f;

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    TSubclassOf<AProjectile> projectileBlueprint;
    
    UPROPERTY(EditDefaultsOnly, Category = "Firing")
    float launchSpeed = 40000;
    
    UTankBarret *barrel = nullptr;
    
    double lastFireTime = 0;
	
};
