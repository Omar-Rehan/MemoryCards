#include "ActorRotator.h"

void UActorRotator::Rotate(float angle) {
	//UE_LOG(LogTemp, Warning, TEXT("Rotate Actor Function"));
	GetOwner()->AddActorLocalRotation(FRotator(0.0f, 180.0f, 0.0f));
}