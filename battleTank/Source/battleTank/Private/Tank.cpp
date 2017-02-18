// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "Tank.h"

// Sets default values
ATank::ATank() {
    
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) {
    
    int32 damagePoints = FPlatformMath::RoundToInt(DamageAmount);
    int32 damageToApply = FMath::Clamp(damagePoints, 0, currentHealth);
    
    currentHealth -= damageToApply;
    if (currentHealth <= 0) {
        UE_LOG(LogTemp, Warning, TEXT("Tank died"))
    }
    
    return damageToApply;
    
}
