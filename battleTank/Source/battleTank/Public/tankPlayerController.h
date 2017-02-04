// Copyright 2017 Robinson Presotto. All rights reserved.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "tankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API AtankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    ATank* GetControlledTank() const;
	
    void BeginPlay() override;
};
