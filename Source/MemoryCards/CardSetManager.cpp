#include "CardSetManager.h"

void UCardSetManager::Initialize(uint8 NumberOfCards) {
	CardSetSize = NumberOfCards;
	InitializeCardSetValues();
}
void UCardSetManager::InitializeCard(TScriptInterface<ICard> Card) {
	uint8 Index = CardSet.Num();
	if (!CardSetValues.IsValidIndex(Index)) {
		UE_LOG(LogTemp, Warning, TEXT("Card Index is out of bounds"));
		return;
	}
	int32 Value = CardSetValues.GetData()[Index];

	Card->SetIndex(Index);
	Card->SetValue(Value);
	CardSet.Push(Card);
}
bool UCardSetManager::OnCardClicked(TScriptInterface<ICard> Card) {
	bool bIsMatch = false;
	bool bCardAlreadyFlipped = (Card == FlippedCard);
	if (bCardAlreadyFlipped) {
		//UE_LOG(LogTemp, Warning, TEXT("A Card Has Been Unflipped"));
		Card->Flip();
		FlippedCard = nullptr;
	} 
	else {
		Card->Flip();
		if (!FlippedCard) {
			//UE_LOG(LogTemp, Warning, TEXT("One Flipped Card"));
			FlippedCard = Card;
		} 
		else {
			//UE_LOG(LogTemp, Warning, TEXT("Two Flipped Cards"));

			int32 Value1 = Card->GetValue();
			int32 Value2 = FlippedCard->GetValue();

			if (Value1 == Value2) {
				UE_LOG(LogTemp, Warning, TEXT("MATCH"));
				Card->Disable();
				FlippedCard->Disable();
				bIsMatch = true;
			} 
			else {
				UE_LOG(LogTemp, Warning, TEXT("WRONG"));
				Card->Flip();
				FlippedCard->Flip();
			}

			FlippedCard = nullptr;
		}
	}

	return bIsMatch;
}
void UCardSetManager::DisableAllCards() {
	for (auto Card : CardSet)
		Card->Disable();
}

void UCardSetManager::InitializeCardSetValues() {
	CardSetValues.Empty();
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