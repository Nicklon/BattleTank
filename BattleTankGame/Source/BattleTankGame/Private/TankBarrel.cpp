// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "BattleTankGame.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	//Move the barrel the right amount this frame
	//Given a a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = FMath::Clamp<float>(RelativeRotation.Pitch + ElevationChange, MinElevationDegrees,MaxElevationDegrees);

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}



