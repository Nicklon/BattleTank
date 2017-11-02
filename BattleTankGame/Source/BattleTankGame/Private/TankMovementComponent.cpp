// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Engine/World.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftToSet, UTankTrack* RightToSet) {
	if (!LeftToSet || !RightToSet) { return; }

	LeftTrack = LeftToSet;
	RightTrack = RightToSet;
}

void UTankMovementComponent::IntendToMoveForwards(float Throw) {
	//float time = GetWorld()->GetTimeSeconds();

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

}


void UTankMovementComponent::IntendTurnRight(float Throw) {

	//UE_LOG(LogTemp, Warning, TEXT("%f : Track movin RIGHT at speed --> %f"), time, Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {

	float time = GetWorld()->GetTimeSeconds();

	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	FVector RightThrow = FVector::CrossProduct(AIForwardIntention, TankForward);

	IntendToMoveForwards(ForwardThrow);
	IntendTurnRight(RightThrow.GetComponentForAxis(EAxis::Z));


}