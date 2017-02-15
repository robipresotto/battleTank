// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankBarret.h"
#include "Projectile.h"
#include "tankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    
    auto tankName = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank C++ Construct"), *tankName);
    
}

void ATank::BeginPlay() {
    Super::BeginPlay();
    
    auto tankName = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s DONKEY: Tank C++ Begin Play"), *tankName);

}

void ATank::AimAt(FVector hitLocation) {
    if (!ensure(tankAimingComponent)) { return; }
    tankAimingComponent->AimAt(hitLocation, launchSpeed);
}

void ATank::Fire() {
    
    if (!ensure(barrel)) { return ;}
    
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
