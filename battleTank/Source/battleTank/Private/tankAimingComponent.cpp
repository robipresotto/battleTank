// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "tankAimingComponent.h"


// Sets default values for this component's properties
UtankAimingComponent::UtankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UtankAimingComponent::setBarrelReference(UStaticMeshComponent *barrelToSet) {
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
        
        UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *ourTankName, *aimDirection.ToString());

    }
    
}

void UtankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
    
    // Work-out difference between current barrel rotation, and AimDirection
    
    auto barrelRotator = barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto deltaRotator = AimAsRotator - barrelRotator;
    
    UE_LOG(LogTemp, Warning, TEXT("AimRotator: %s"), *deltaRotator.ToString());
    
    // Move the barrel the right amount this frame
    // Given a max elevation speed, and the frame time
    
}
