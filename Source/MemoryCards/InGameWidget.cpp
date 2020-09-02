#include "InGameWidget.h"

void UInGameWidget::Setup() {
	if (NumberOfMovesTextBlock) {
		AMemoryCardsGameModeBase* GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		GameMode->SetNumOfMovesTextBlock(NumberOfMovesTextBlock);
	}

	if (CardButton_0)
		CardButton_0->Initialize();
	if (CardButton_1)
		CardButton_1->Initialize();
	if (CardButton_2)
		CardButton_2->Initialize();
	if (CardButton_3)
		CardButton_3->Initialize();
	if (CardButton_4)
		CardButton_4->Initialize();
	if (CardButton_5)
		CardButton_5->Initialize();
	if (CardButton_6)
		CardButton_6->Initialize();
	if (CardButton_7)
		CardButton_7->Initialize();
}