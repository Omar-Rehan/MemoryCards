#include "InGameWidget.h"

void UInGameWidget::Setup() {
	AMemoryCardsGameModeBase* GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	if (NumberOfMovesTextBlock) {
		GameMode->SetNumOfMovesTextBlock(NumberOfMovesTextBlock);
	}

	if (CardsGrid) {
		int32 NumOfCards = CardsGrid->GetChildrenCount();
		GameMode->SetNumOfCards(NumOfCards);
		for (int32 Index = 0; Index < NumOfCards; Index++) {
			UCardButton* Card = Cast<UCardButton>(CardsGrid->GetChildAt(Index));
			Card->Initialize();
			CardButtons.Add(Card);
		}
	}
}