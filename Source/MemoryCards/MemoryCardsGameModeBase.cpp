#include "MemoryCardsGameModeBase.h"

AMemoryCardsGameModeBase::AMemoryCardsGameModeBase() {
	CurrentWidget = nullptr;
	InitialWidgetClass = nullptr; // to be changed from the editor
}

void AMemoryCardsGameModeBase::BeginPlay() {
	Super::BeginPlay();
	ChangeMenuWidget(InitialWidgetClass);
	InitializeCardSet();
}

void AMemoryCardsGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass) {
	if (CurrentWidget) {
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass) {
		CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);
		if (CurrentWidget) CurrentWidget->AddToViewport();
	}
}

void AMemoryCardsGameModeBase::InitializeCardSet() {
	CardSetSize = 8; // TODO: find a automated way to do it

	for (int32 i = 1; i <= CardSetSize; i++) {
		CardSetValues.Add(i);
		CardSetValues.Add(i);
	}
	for (int32 i = 0; i < 40; i++) {
		int32 Index1 = FMath::RandRange(0, CardSetSize - 1);
		int32 Index2 = FMath::RandRange(0, CardSetSize - 1);
		CardSetValues.Swap(Index1, Index2);
	}
}
int32 AMemoryCardsGameModeBase::GetCardValue(uint16 Index) const {
	if (CardSetValues.IsValidIndex(Index))
		return CardSetValues.GetData()[Index];
	else {
		UE_LOG(LogTemp, Warning, TEXT("Card Index is out of bounds"));
		return -1;
	}
}
void AMemoryCardsGameModeBase::OnCardClicked(TScriptInterface<ICard> Card) {
	int32 OldIndex = FlippedCards.Find(Card);
	bool bCardAlreadyFlipped = (OldIndex != INDEX_NONE);
	if (bCardAlreadyFlipped) {
		FlippedCards.RemoveAt(OldIndex);
		Card->Flip();
		UE_LOG(LogTemp, Warning, TEXT("A Card Has Been Unflipped"));
	}
	else {
		FlippedCards.Add(Card);
		uint8 NumOfFlippedCards = FlippedCards.Num();

		if (NumOfFlippedCards == 1) {
			Card->Flip();
			UE_LOG(LogTemp, Warning, TEXT("One Flipped Card"));
		} 
		else if (NumOfFlippedCards == 2) {
			Card->Flip();
			UE_LOG(LogTemp, Warning, TEXT("Two Flipped Cards"));
			
			if (IsMatch()) {
				UE_LOG(LogTemp, Warning, TEXT("MATCH"));
				FlippedCards.GetData()[0]->Disable();
				FlippedCards.GetData()[1]->Disable();
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("WRONG"));
				FlippedCards.GetData()[0]->Flip();
				FlippedCards.GetData()[1]->Flip();
			}
			
			FlippedCards.Empty();
		}
	}
}
bool AMemoryCardsGameModeBase::IsMatch() {
	TScriptInterface<ICard> Card1 = FlippedCards.GetData()[0];
	TScriptInterface<ICard> Card2 = FlippedCards.GetData()[1];
	return (Card1->GetValue() == Card2->GetValue());
}