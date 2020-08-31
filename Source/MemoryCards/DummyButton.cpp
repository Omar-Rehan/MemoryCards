#include "DummyButton.h"

UDummyButton::UDummyButton() {
	Value = -1;
	Index = 255;
	bHidden = true;
	
	OnClicked.AddDynamic(this, &UDummyButton::HandleClick);
}

void UDummyButton::Initialize() {
	CurrentGameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	if (Value == -1)
		CurrentGameMode->InitializeCard(this);
}

void UDummyButton::Flip() {
	UpdateText();
}
void UDummyButton::Disable() {
	SetIsEnabled(false);
}
void UDummyButton::HandleClick() {
	if (CurrentGameMode)
		CurrentGameMode->OnCardClicked(this);
}

void UDummyButton::SetValue(int32 NewValue) {
	Value = NewValue;
}
int32 UDummyButton::GetValue() {
	return Value;
}

void UDummyButton::SetIndex(uint8 NewIndex) {
	Index = NewIndex;
}
uint8 UDummyButton::GetIndex() {
	return Index;
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