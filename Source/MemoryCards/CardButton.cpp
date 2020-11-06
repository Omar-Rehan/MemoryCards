#include "CardButton.h"

UCardButton::UCardButton() {
	Value = -1;
	Index = 255;
	bHidden = true;

	OnClicked.AddDynamic(this, &UCardButton::HandleClick);
}

void UCardButton::Initialize() {
	GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!GameMode) {
		return;
	}

	if (Value == -1)
		GameMode->InitializeCard(this);
}

void UCardButton::RequestFlip(bool bDelayed) {
	if (!bDelayed) {
		Flip();
		return;
	}

	FTimerHandle Handle;
	GameMode->GetWorldTimerManager().SetTimer(Handle, this, &UCardButton::Flip, 1.0f, false, 2.0f);
	bBusy = true;
}
void UCardButton::Flip() {
	if (bHidden)
		UE_LOG(LogTemp, Warning, TEXT("CardButton::Flip -> Show %d"), Value)
	else
		UE_LOG(LogTemp, Warning, TEXT("CardButton::Flip -> Hide %d"), Value)

	bHidden = !bHidden;
	bBusy = false;
	Visibility = ESlateVisibility::Visible;
	UpdateDisplay();
}
void UCardButton::Disable() {
	SetIsEnabled(false);
}

void UCardButton::HandleClick() {
	if (bBusy) return;

	if (GameMode)
		GameMode->HandleCardClick(this);
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

void UCardButton::UpdateDisplay() {
	if (!TextBlock) {
		UE_LOG(LogTemp, Warning, TEXT("This button's text block reference is a nullptr"));
		return;
	}
	
	FString NewString = bHidden ? FString() : FString::FromInt(Value);
	FText NewText = FText::FromString(NewString);
	TextBlock->SetText(NewText);
}