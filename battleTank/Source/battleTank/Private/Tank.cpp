// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // No need to protect points as added at construction
    tankAimingComponent = CreateDefaultSubobject<UtankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::SetBarrelReference(UStaticMeshComponent *barrelToSet) {
    tankAimingComponent->setBarrelReference(barrelToSet);
}

void ATank::AimAt(FVector hitLocation) {
    tankAimingComponent->AimAt(hitLocation, launchSpeed);
}
