// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "tankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API AtankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    
    ATank* GetControlledTank() const;
    ATank* GetPlayerTank() const;
    
    void BeginPlay() override;
	
};
