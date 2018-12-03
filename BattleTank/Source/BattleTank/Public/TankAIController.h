// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Decelerations

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
		
	// How close can the AI tank get
	float AcceptanceRadius = 3000;
};