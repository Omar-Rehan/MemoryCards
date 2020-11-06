#include "CardSetManager.h"

void UCardSetManager::Initialize(uint8 NumberOfCards) {
	CardSetSize = NumberOfCards;
	CardSet.Empty();
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
bool UCardSetManager::HandleCardClick(TScriptInterface<ICard> Card) {
	UE_LOG(LogTemp, Warning, TEXT("CardSetManager handle card click function"));
	bool bIsMatch = false;
	bool bCardAlreadyFlipped = (Card == FlippedCard);
	UE_LOG(LogTemp, Warning, TEXT("Is this particular card already flipped? %d"), bCardAlreadyFlipped);
	if (bCardAlreadyFlipped) {
		Card->RequestFlip(false);
		FlippedCard = nullptr;
	} 
	else {
		Card->RequestFlip(false);
		if (!FlippedCard) { // Only non-hidden card
			FlippedCard = Card;
			UE_LOG(LogTemp, Warning, TEXT("Only shown card"));
		} 
		else { // second non-hidden card
			UE_LOG(LogTemp, Warning, TEXT("Two cards shown"));
			int32 Value1 = Card->GetValue();
			int32 Value2 = FlippedCard->GetValue();

			if (Value1 == Value2) {
				UE_LOG(LogTemp, Warning, TEXT("MATCH!"));
				Card->Disable();
				FlippedCard->Disable();
				bIsMatch = true;
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("MISMATCH! %d %d"), Card->GetValue(), FlippedCard->GetValue());
				Card->RequestFlip(true);
				FlippedCard->RequestFlip(true);
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