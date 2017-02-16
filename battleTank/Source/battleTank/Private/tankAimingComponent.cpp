// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankBarret.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "tankAimingComponent.h"

// Sets default values for this component's properties
UtankAimingComponent::UtankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UtankAimingComponent::Initialise(UTankBarret *barrelToSet, UTankTurret *turretToSet) {
    barrel = barrelToSet;
    turret = turretToSet;
}

void UtankAimingComponent::AimAt(FVector HitLocation) {
    
    if (!ensure(barrel)) { return; }
    
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
         false,
         0,
         0,
         ESuggestProjVelocityTraceOption::DoNotTrace
         )
        ) {
    
        auto ourTankName = GetOwner()->GetName();
        auto aimDirection = outLaunchVelocity.GetSafeNormal();
        
        MoveBarrelTowards(aimDirection);
        
    }
    
}

void UtankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
    
    if (!ensure(barrel) || !ensure(turret)) { return; }
    
    // Work-out difference between current barrel rotation, and AimDirection
    auto barrelRotator = barrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto deltaRotator = AimAsRotator - barrelRotator;
        
    barrel->elevate(deltaRotator.Pitch);
    turret->rotate(deltaRotator.Yaw);
    
}

void UtankAimingComponent::Fire() {
    
    if (!ensure(barrel && projectileBlueprint)) { return ;}
    
    // if is reloaded and has barrel => Fire
    if ((FPlatformTime::Seconds() - lastFireTime) > reloadTimeInSeconds) {
        
        // spawn a projectile at the socket location on the barrel
        auto projectile = GetWorld()->SpawnActor<AProjectile>(
                                                              projectileBlueprint,
                                                              barrel->GetSocketLocation(FName("Projectile")),
                                                              barrel->GetSocketRotation(FName("Projectile"))
                                                              );
        
        projectile->LaunchProjectile(launchSpeed);
        lastFireTime = FPlatformTime::Seconds();
        
    }
    
}

