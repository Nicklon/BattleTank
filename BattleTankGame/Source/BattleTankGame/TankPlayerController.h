// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnyWhere)
	float LineTraceRange = 1000000.f;

	UPROPERTY(EditAnyWhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnyWhere)
	float CrossHairYLocation = 0.33333;

	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector &Out_HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OUT_LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OUT_HitLocation) const;

};
