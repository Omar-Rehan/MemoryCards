#include "DifficultySelectionWidget.h"

void UDifficultySelectionWidget::Setup(UWorld* WorldReference) {
	GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(WorldReference));

	EasyButton->OnClicked.AddDynamic(this, &UDifficultySelectionWidget::HandleEasyButtonClick);
	MediumButton->OnClicked.AddDynamic(this, &UDifficultySelectionWidget::HandleMediumButtonClick);
	HardButton->OnClicked.AddDynamic(this, &UDifficultySelectionWidget::HandleHardButtonClick);
}

void UDifficultySelectionWidget::HandleEasyButtonClick() {
	if (GameMode)
		GameMode->ReplaceWidgets(EWidgets::EasyGameMode);
}
void UDifficultySelectionWidget::HandleMediumButtonClick() {
	if (GameMode)
		GameMode->ReplaceWidgets(EWidgets::MediumGameMode);
}
void UDifficultySelectionWidget::HandleHardButtonClick() {
	if (GameMode)
		GameMode->ReplaceWidgets(EWidgets::HardGameMode);
}