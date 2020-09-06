#include "GameEndWidget.h"

void UGameEndWidget::Setup(UWorld* WorldReference) {
	GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(WorldReference));

	PlayAgainButton->OnClicked.AddDynamic(this, &UGameEndWidget::HandlePlayAgainButtonClick);
	ReturnToMenuButton->OnClicked.AddDynamic(this, &UGameEndWidget::HandleReturnToMenuButtonClick);
}

void UGameEndWidget::HandlePlayAgainButtonClick() {
	if (GameMode)
		GameMode->PlayAgain();
}
void UGameEndWidget::HandleReturnToMenuButtonClick() {
	if (GameMode)
		GameMode->ReplaceWidgets(EWidgets::MainMenu);
}