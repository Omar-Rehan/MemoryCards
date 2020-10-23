#include "RotatingPawn.h"

void ARotatingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("HorizontalRotation", EKeys::MouseX, 1.0f));
	PlayerInputComponent->BindAxis("HorizontalRotation", this, &ARotatingPawn::AddControllerYawInput);

	UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("VerticalRotation", EKeys::MouseY, -1.0f));
	PlayerInputComponent->BindAxis("VerticalRotation", this, &ARotatingPawn::AddControllerPitchInput);
}