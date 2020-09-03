#include "InGameWidget.h"

void UInGameWidget::Setup() {
	if (NumberOfMovesTextBlock) {
		AMemoryCardsGameModeBase* GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		GameMode->SetNumOfMovesTextBlock(NumberOfMovesTextBlock);
	}

	if (CardsGrid) {
		int32 NumOfCards = CardsGrid->GetChildrenCount();
		for (int32 Index = 0; Index < NumOfCards; Index++) {
			UCardButton* Card = Cast<UCardButton>(CardsGrid->GetChildAt(Index));
			Card->Initialize();
			CardButtons.Add(Card);
		}
	}
}