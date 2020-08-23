#include "DummyButton.h"

UDummyButton::UDummyButton() {
	/// Determine the button index
	FString ButtonIndex = GetName().RightChop(4);
	Index = FCString::Atoi(*ButtonIndex);
	Value = -1;
	
	/// Ensure the number is hidden
	bHidden = true;
	UpdateText();
	
	/// Bind the "HandleClick" function to the OnClicked event
	OnClicked.AddDynamic(this, &UDummyButton::HandleClick);
}

void UDummyButton::HandleClick() {
	FlipCard();
}

void UDummyButton::FlipCard() {
	if (Value == -1) {
		AMemoryCardsGameModeBase* CurrentGameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		if (CurrentGameMode)
			Value = CurrentGameMode->GetCardValue(Index);
	}

	bHidden = !bHidden;
	UpdateText();
}
void UDummyButton::UpdateText() {
	if (!TextBlock) {
		UE_LOG(LogTemp, Warning, TEXT("This button's text block reference is a nullptr"));
		return;
	}

	FString NewString = bHidden ? FString() : FString::FromInt(Value);
	FText NewText = FText::FromString(NewString);
	TextBlock->SetText(NewText);
}