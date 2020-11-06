#include "CardInfoComponent.h"

UCardInfoComponent::UCardInfoComponent() {
	Value = -1;
	Index = 255;
	bBusy = false;
	bHidden = true;
}

void UCardInfoComponent::Initialize() {
	GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GameMode) {
		UE_LOG(LogTemp, Warning, TEXT("GameMode cast failed"));
		return;
	}

	if (Value == -1) {
		GameMode->InitializeCard(this);

		FString MaterialPath = "/Game/Blueprints/Materials/BP_DefaultCardFrontMaterial_" + FString::FromInt(Value);
		UE_LOG(LogTemp, Warning, TEXT("Value: %d"), Value);
		UMaterial* CardMaterial = LoadObject<UMaterial>(nullptr, *MaterialPath);
		if (CardMaterial) {
			GetOwner()->FindComponentByClass<UStaticMeshComponent>()->SetMaterial(0, CardMaterial);
		}
	}
}

void UCardInfoComponent::RequestFlip(bool bDelayed) {
	if (!bDelayed) {
		UE_LOG(LogTemp, Warning, TEXT("Immediate flip requested on value %d"), Value);
		Flip();
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Delayed flip requested on value %d"), Value);
	FTimerHandle Handle;
	GameMode->GetWorldTimerManager().SetTimer(Handle, this, &UCardInfoComponent::Flip, 1.0f, false, 2.0f);
	bBusy = true;
}
void UCardInfoComponent::Flip() {
	if (bHidden)
		UE_LOG(LogTemp, Warning, TEXT("CardButton::Flip -> Show %d"), Value)
	else
		UE_LOG(LogTemp, Warning, TEXT("CardButton::Flip -> Hide %d"), Value);

	bHidden = !bHidden;
	bBusy = false;
	UpdateDisplay();
}
void UCardInfoComponent::Disable() {
	UE_LOG(LogTemp, Warning, TEXT("Destroy card with value %d"), Value);
	GetOwner()->Destroy();
}

void UCardInfoComponent::HandleClick() {
	UE_LOG(LogTemp, Warning, TEXT("Card Info Component handle click function"));
	if (bBusy) {
		UE_LOG(LogTemp, Warning, TEXT("Card Info Component busy wont handle click"));
		return;
	}

	if (GameMode)
		GameMode->HandleCardClick(this);
}

void UCardInfoComponent::SetValue(int32 NewValue) {
	Value = NewValue;
}
int32 UCardInfoComponent::GetValue() {
	return Value;
}

void UCardInfoComponent::SetIndex(uint8 NewIndex) {
	Index = NewIndex;
}
uint8 UCardInfoComponent::GetIndex() {
	return Index;
}

void UCardInfoComponent::UpdateDisplay() {
	UE_LOG(LogTemp, Warning, TEXT("Update display function"));
	UActorRotator* RotatorComponent = GetOwner()->FindComponentByClass<UActorRotator>();
	if (RotatorComponent) {
		RotatorComponent->Rotate();
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Rotator component not found"));
	}
}

