// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;


UCLASS()
class BATTLETANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	UFUNCTION()
	void OnPossedTankDeath();
protected:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 3000;

private:
	ATank* PossessedTank = nullptr;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetPawn(APawn* InPawn) override;

};

