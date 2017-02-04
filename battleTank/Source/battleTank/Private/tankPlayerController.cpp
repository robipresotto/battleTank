// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "tankPlayerController.h"

ATank* AtankPlayerController::GetControlledTank() const {
    return Cast<ATank>(GetPawn());
}

