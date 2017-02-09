

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankTurret;
class UTankBarret;
class UtankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
    
public:
    
    void AimAt(FVector hitLocation);
    
    UFUNCTION(BlueprintCallable, Category = Firing)
    void Fire();
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetTurretReference(UTankTurret *turretToSet);
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarret *barrelToSet);
    
protected:
    UtankAimingComponent *tankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float reloadTimeInSeconds = 3.f;

    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AProjectile> projectileBlueprint;
    
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float launchSpeed = 40000;
    
    UTankBarret *barrel = nullptr;
    
    double lastFireTime = 0;
	
};
