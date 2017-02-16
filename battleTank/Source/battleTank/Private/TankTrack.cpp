// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack() {
 
    PrimaryComponentTick.bCanEverTick = false;
    
}

void UTankTrack::BeginPlay() {
    OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) {

    DriveTrack();
    ApplySidewaysForce();
    currentThrottle = 0;

}

void UTankTrack::ApplySidewaysForce() {
    // Work-out the required acceleration this frame to correct
    auto slippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
    auto deltaTime = GetWorld()->GetDeltaSeconds();
    auto correctionAcceleration = -slippageSpeed / deltaTime * GetRightVector();
    
    // Calculate and apply sideways (F = m a)
    auto tankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
    auto correctionForce = (tankRoot->GetMass() * correctionAcceleration) / 2; // Two tracks
    tankRoot->AddForce(correctionForce);
}

void UTankTrack::SetThrottle(float throttle) {
        
    currentThrottle = FMath::Clamp<float>(currentThrottle + throttle, -1, 1);
    
}

void UTankTrack::DriveTrack() {
    auto forceApplied = GetForwardVector() * currentThrottle * trackMaxDrivingForce;
    auto forceLocation = GetComponentLocation();
    auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}
