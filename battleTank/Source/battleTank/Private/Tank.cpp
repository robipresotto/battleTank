// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankBarret.h"
#include "Projectile.h"
#include "tankAimingComponent.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    // No need to protect points as added at construction
    tankAimingComponent = CreateDefaultSubobject<UtankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::SetBarrelReference(UTankBarret *barrelToSet) {
    tankAimingComponent->setBarrelReference(barrelToSet);
    barrel = barrelToSet;
}

void ATank::SetTurretReference(UTankTurret *turretToSet) {
    tankAimingComponent->setTurretReference(turretToSet);
}

void ATank::AimAt(FVector hitLocation) {
    tankAimingComponent->AimAt(hitLocation, launchSpeed);
}

void ATank::Fire() {
        
    if (!barrel) {return;}
    
    // spawn a projectile at the socket location on the barrel
    
    auto projectile = GetWorld()->SpawnActor<AProjectile>(
        projectileBlueprint,
        barrel->GetSocketLocation(FName("Projectile")),
        barrel->GetSocketRotation(FName("Projectile"))
    );
    
    projectile->LaunchProjectile(launchSpeed);
    
}
