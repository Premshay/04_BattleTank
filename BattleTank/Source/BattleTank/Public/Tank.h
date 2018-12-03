// Copyright None LTD.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

// Forward Decleration
class UTankBarrel; 
class UTankTurret;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;

	// Local barrel reference for spawning projectiles
	UTankBarrel* Barrel = nullptr; // TODO remove

	double LastFireTime = 0;
};
