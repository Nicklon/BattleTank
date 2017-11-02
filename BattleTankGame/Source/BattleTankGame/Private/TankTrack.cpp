// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"

void UTankTrack::SetThrottle(float Throttle) {
	float time = GetWorld()->GetTimeSeconds();
	//float NewSpeed = FMath::Clamp<float>(Throttle, 0, MaxSpeed);
	FString aux = "LEFT";

	if (!left) {
		aux = "RIGHT";
	}

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);


	//UE_LOG(LogTemp, Warning, TEXT("%f : %s Track movin at speed --> %f"), time, *aux, Throttle);

}


