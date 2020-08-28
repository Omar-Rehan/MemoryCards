#include "DummyButton.h"

AMemoryCardsGameModeBase* UDummyButton::CurrentGameMode = nullptr;

UDummyButton::UDummyButton() {
	FString ButtonIndex = GetName().RightChop(4);
	Index = FCString::Atoi(*ButtonIndex);
	
	Value = -1;
	bHidden = true;
	
	OnClicked.AddDynamic(this, &UDummyButton::HandleClick);
}

void UDummyButton::Flip() {
	UpdateText();
}
void UDummyButton::Disable() {
	SetIsEnabled(false);
}
void UDummyButton::HandleClick() {
	if (!CurrentGameMode) // TODO: Find a better place for this
		CurrentGameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	if (CurrentGameMode) {
		bool bIsValueAssigned = (Value != -1);
		if (!bIsValueAssigned) {
			CurrentGameMode->InitializeCard(this);
		}
		
		CurrentGameMode->OnCardClicked(this);
	}
}

void UDummyButton::SetValue(int32 NewValue) {
	Value = NewValue;
}
int32 UDummyButton::GetValue() {
	return Value;
}

void UDummyButton::SetIndex(int32 NewIndex) {
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