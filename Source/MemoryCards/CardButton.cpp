#include "CardButton.h"

UCardButton::UCardButton() {
	//UE_LOG(LogTemp, Warning, TEXT("Card Button Constructor"));
	Value = -1;
	Index = 255;
	bHidden = true;

	OnClicked.AddDynamic(this, &UCardButton::HandleClick);
}

void UCardButton::Initialize() {
	//UE_LOG(LogTemp, Warning, TEXT("Initialize"));
	CurrentGameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	if (!CurrentGameMode)
		UE_LOG(LogTemp, Warning, TEXT("GameMode cast failed"));

	if (Value == -1)
		CurrentGameMode->InitializeCard(this);
}

void UCardButton::Flip() {
	UpdateText();
}
void UCardButton::Disable() {
	SetIsEnabled(false);
}
void UCardButton::HandleClick() {
	if (CurrentGameMode)
		CurrentGameMode->OnCardClicked(this);
}

void UCardButton::SetValue(int32 NewValue) {
	Value = NewValue;
}
int32 UCardButton::GetValue() {
	return Value;
}

void UCardButton::SetIndex(uint8 NewIndex) {
	Index = NewIndex;
}
uint8 UCardButton::GetIndex() {
	return Index;
}

void UCardButton::UpdateText() {
	if (!TextBlock) {
		UE_LOG(LogTemp, Warning, TEXT("This button's text block reference is a nullptr"));
		return;
	}

	bHidden = !bHidden;
	FString NewString = bHidden ? FString() : FString::FromInt(Value);
	FText NewText = FText::FromString(NewString);
	TextBlock->SetText(NewText);
}