// Gustavo Ardaya


#include "Items/PickUps/WarriorPickUpBase.h"
#include "Components/SphereComponent.h"

AWarriorPickUpBase::AWarriorPickUpBase()
{ 	
	PrimaryActorTick.bCanEverTick = false;

	PickupCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PickupCollisionSphere"));
	SetRootComponent(PickupCollisionSphere);
	PickupCollisionSphere->InitSphereRadius(50.f);
	PickupCollisionSphere->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnPickupCollisionSphereBeginOverlap);

}

void AWarriorPickUpBase::OnPickupCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

