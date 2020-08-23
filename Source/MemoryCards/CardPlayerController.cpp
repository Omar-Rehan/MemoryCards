#include "CardPlayerController.h"

void ACardPlayerController::BeginPlay() {
	Super::BeginPlay();
	bShowMouseCursor = true;
	SetInputMode(FInputModeUIOnly());
}