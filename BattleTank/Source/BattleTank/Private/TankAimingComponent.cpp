// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called every frame


void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed)
{
	if (!Barrel) { return;  }
	
	this;
	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
		);
		if (bHaveAimSolution)
	{
	auto AimDirection = OutLaunchVelocity.GetSafeNormal();
	MoveBarrelTowards(AimDirection);
	}
	// if no solution then do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// get difference between current barrel  rotation and aimdirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT ("AimAsRotator: %s"), *DeltaRotator.ToString());
	// move barrel the right amount this frame

	// given a max elevation speed and the frame time

}