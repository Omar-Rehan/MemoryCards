#include "DummyButton.h"

AMemoryCardsGameModeBase* UDummyButton::CurrentGameMode = nullptr;

UDummyButton::UDummyButton() {
	FString ButtonIndex = GetName().RightChop(4);
	Index = FCString::Atoi(*ButtonIndex);
	
	Value = -1;
	bHidden = true;
	
	/// Bind the "HandleClick" function to the OnClicked event
	OnClicked.AddDynamic(this, &UDummyButton::HandleClick);
}

void UDummyButton::HandleClick() {
	if (!CurrentGameMode) // TODO: Find a better place for this
		CurrentGameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	if (CurrentGameMode)
		CurrentGameMode->OnCardClicked(this);
}

void UDummyButton::Flip() {
	bool bIsValueAssigned = (Value != -1);
	if (!bIsValueAssigned && CurrentGameMode) {
		Value = CurrentGameMode->GetCardValue(Index);
	}

	UpdateText();
}
void UDummyButton::Disable() {
	SetIsEnabled(false);
}
int32 UDummyButton::GetValue() {
	return Value;
}

void UDummyButton::UpdateText() {
	if (!TextBlock) {
		UE_LOG(LogTemp, Warning, TEXT("This button's text block reference is a nullptr"));
		return;
	}

	bHidden = !bHidden;
	FString NewString = bHidden ? FString() : FString::FromInt(Value);
	FText NewText = FText::FromString(NewString);
	TextBlock->SetText(NewText);
}