// Copyright None LTD.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward Decelerations
class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//Return OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
	//Start the tank moving the barrel so a shot would hit 
	//where the crosshair intersects the world
	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;



};
