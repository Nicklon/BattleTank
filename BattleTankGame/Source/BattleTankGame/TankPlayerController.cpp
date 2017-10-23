// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTankGame.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	ATank* ControlledTank = ATankPlayerController::GetControlledTank();

	if (ControlledTank == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possesing Tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);




}



