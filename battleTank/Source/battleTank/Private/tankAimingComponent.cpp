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

// Called when the game starts
void UtankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UtankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
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
         false,
         0,
         0,
         ESuggestProjVelocityTraceOption::DoNotTrace
         )
        ) {
    
        auto ourTankName = GetOwner()->GetName();
        auto aimDirection = outLaunchVelocity.GetSafeNormal();
        UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *ourTankName, *aimDirection.ToString());

    }
    
}
