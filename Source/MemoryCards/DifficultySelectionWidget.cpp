#include "DifficultySelectionWidget.h"

void UDifficultySelectionWidget::Setup(UWorld* WorldReference) {
	GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(WorldReference));

	EasyButton->OnClicked.AddDynamic(this, &UDifficultySelectionWidget::HandleEasyButtonClick);
	MediumButton->OnClicked.AddDynamic(this, &UDifficultySelectionWidget::HandleMediumButtonClick);
	HardButton->OnClicked.AddDynamic(this, &UDifficultySelectionWidget::HandleHardButtonClick);
}

void UDifficultySelectionWidget::LoadGame() {
	if (GameMode->GetIs2D())
		GameMode->ReplaceWidgets(GameMode->SelectedDiffculty);
	else {
		GameMode->ClearWidgets();
		GameMode->ReplaceMap(GameMode->SelectedDiffculty);
	}
}

void UDifficultySelectionWidget::HandleEasyButtonClick() {
	if (!GameMode) return;
	
	GameMode->SelectedDiffculty = EWidgets::EasyGameMode;
	LoadGame();
}
void UDifficultySelectionWidget::HandleMediumButtonClick() {
	if (!GameMode) return;
		
	GameMode->SelectedDiffculty = EWidgets::MediumGameMode;
	LoadGame();
}
void UDifficultySelectionWidget::HandleHardButtonClick() {
	if (!GameMode) return;

	GameMode->SelectedDiffculty = EWidgets::HardGameMode;
	LoadGame();
}