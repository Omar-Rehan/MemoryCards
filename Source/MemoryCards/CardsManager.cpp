#include "CardsManager.h"

UCardsManager::UCardsManager() {
	CardSetSize = 8;
}

void UCardsManager::InitializeCardSet() {
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
int32 UCardsManager::GetCardValue(uint8 Index) const {
	if (CardSetValues.IsValidIndex(Index))
		return CardSetValues.GetData()[Index];
	else {
		UE_LOG(LogTemp, Warning, TEXT("Card Index is out of bounds"));
		return -1;
	}
}
void UCardsManager::OnCardClicked(TScriptInterface<ICard> Card) {
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

bool UCardsManager::IsMatch() {
	TScriptInterface<ICard> Card1 = FlippedCards.GetData()[0];
	TScriptInterface<ICard> Card2 = FlippedCards.GetData()[1];
	return (Card1->GetValue() == Card2->GetValue());
}