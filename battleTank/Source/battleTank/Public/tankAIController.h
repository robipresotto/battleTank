// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "AIController.h"
#include "tankAIController.generated.h"


UCLASS()
class BATTLETANK_API AtankAIController : public AAIController
{
	GENERATED_BODY()
    
protected:
    
    // How close can the AI tank get close to the player
    UPROPERTY(EditDefaultsOnly, Category = "Setup")
    float AcceptanceRadius = 80000;
	
private:
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
	
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;

};
