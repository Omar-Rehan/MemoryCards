#include "InGameWidget.h"

void UInGameWidget::Setup(UWorld* WorldReference) {
	GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(WorldReference));

	if (GameMode) {
		GameMode->SetNumOfMovesTextBlock(NumberOfMovesTextBlock);

		int32 NumOfCards = CardsGrid->GetChildrenCount();
		GameMode->StartGame(NumOfCards);
		
		for (int32 Index = 0; Index < NumOfCards; Index++) {
			UCardButton* Card = Cast<UCardButton>(CardsGrid->GetChildAt(Index));
			Card->Initialize();
			CardButtons.Add(Card);
		}
	}
}