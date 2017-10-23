// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTankGame.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* AIControlledTank = ATankAIController::GetControlledTank();

	if (AIControlledTank == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController Not Possesing Tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController possesing: %s"), *(AIControlledTank->GetName()));
	}

	ATank* PlayerControlledTank = ATankAIController::GetPlayerTank();

	if (PlayerControlledTank == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController Not Finding Player Tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AIPlayerController aiming at : %s"), *(PlayerControlledTank->GetName()));
	}

}
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}




