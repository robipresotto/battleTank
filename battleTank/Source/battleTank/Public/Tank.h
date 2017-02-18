

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn {
    
GENERATED_BODY()
    
public:
    
    // Called by the engine when actor damage is dealt
    virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;
    
    // Return current health as a percentage of starting health, between 0 and 1
    UFUNCTION(BlueprintPure, Category = "Health")
    float GetHealthPercent() const;
    
private:
    
    ATank();

    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    int32 startingHealth = 100;
    
    UPROPERTY(VisibleAnywhere, Category = "Health")
    int32 currentHealth = startingHealth;
    	
};
