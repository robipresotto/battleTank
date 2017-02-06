// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarret;
class UtankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
    
public:
    void AimAt(FVector hitLocation);
    
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
    
    UPROPERTY(EditAnywhere, Category = Firing)
    float launchSpeed = 100000; // TODO: Find sensible default value
	
};
