// Copyright 2017 Robinson Presotto. All rights reserved.

#include "battleTank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    
    collisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
    SetRootComponent(collisionMesh);
    collisionMesh->SetNotifyRigidBodyCollision(true);
    collisionMesh->SetVisibility(false);
    
    launchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
    launchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    
    projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
    projectileMovement->bAutoActivate = false;
    
    impactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
    impactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    impactBlast->bAutoActivate = false;

    explosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion Force"));
    explosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
    
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
    collisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);

}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) {
    
    launchBlast->Deactivate();
    impactBlast->Activate();
    explosionForce->FireImpulse();
    
    SetRootComponent(impactBlast);
    collisionMesh->DestroyComponent();
    
    FTimerHandle timer;
    GetWorld()->GetTimerManager().SetTimer(timer, this, &AProjectile::OnTimerExpire, DestroyDelay, false);

}

void AProjectile::OnTimerExpire() {
    Destroy();
}

void AProjectile::LaunchProjectile(float Speed) {
    
    projectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
    projectileMovement->Activate();
    
}
