// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankBarret.h"
#include "tankAimingComponent.h"


// Sets default values for this component's properties
UtankAimingComponent::UtankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO: Should this really tick?

	// ...
}

void UtankAimingComponent::setBarrelReference(UTankBarret *barrelToSet) {
    barrel = barrelToSet;
}


void UtankAimingComponent::AimAt(FVector HitLocation, float launchSpeed) {
    
    if (!barrel) { return; }
    
    FVector outLaunchVelocity;
    FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));
    
    // Calculate the OutLaunchVelocity

    if (UGameplayStatics::SuggestProjectileVelocity
        (
         this,
         outLaunchVelocity,
         startLocation,
         HitLocation,
         launchSpeed,
         ESuggestProjVelocityTraceOption::DoNotTrace
         )
        ) {
    
        auto ourTankName = GetOwner()->GetName();
        auto aimDirection = outLaunchVelocity.GetSafeNormal();
        
        MoveBarrelTowards(aimDirection);
        
        auto time = GetWorld()->GetTimeSeconds();
        UE_LOG(LogTemp, Warning, TEXT("%f - Aim solution found"), time);

    } else {
        
        auto time = GetWorld()->GetTimeSeconds();
        UE_LOG(LogTemp, Warning, TEXT("%f - No aim solve found"), time);

    }
    
}

void UtankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
    
    // Work-out difference between current barrel rotation, and AimDirection
    
    auto barrelRotator = barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto deltaRotator = AimAsRotator - barrelRotator;
        
    barrel->elevate(5); //TODO: Remove magic number
    
}
