#include "ActorRotator.h"

UActorRotator::UActorRotator() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UActorRotator::BeginPlay() {
	Super::BeginPlay();
}

void UActorRotator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UActorRotator::RotateActor(float angle) {
	UE_LOG(LogTemp, Warning, TEXT("Rotate Actor!"));
	
}