// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "AIController.h"
#include "tankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API AtankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
    
    ATank* GetControlledTank() const;
    ATank* GetPlayerTank() const;
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
	
    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;
    
    // How close can the AI tank get close to the player
    float AcceptanceRadius = 3000;

};
