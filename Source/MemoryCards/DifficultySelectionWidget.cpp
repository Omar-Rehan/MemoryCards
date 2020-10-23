#include "DifficultySelectionWidget.h"

void UDifficultySelectionWidget::Setup(UWorld* WorldReference) {
	GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(WorldReference));

	EasyButton->OnClicked.AddDynamic(this, &UDifficultySelectionWidget::HandleEasyButtonClick);
	MediumButton->OnClicked.AddDynamic(this, &UDifficultySelectionWidget::HandleMediumButtonClick);
	HardButton->OnClicked.AddDynamic(this, &UDifficultySelectionWidget::HandleHardButtonClick);
}

void UDifficultySelectionWidget::HandleEasyButtonClick() {
	if (GameMode) {
		if (GameMode->GetIs2D())
			GameMode->ReplaceWidgets(EWidgets::EasyGameMode);
		else {
			GameMode->ClearWidgets();
			UGameplayStatics::OpenLevel(GetWorld(), "Easy3DGame");
		}
	}
}
void UDifficultySelectionWidget::HandleMediumButtonClick() {
	if (GameMode) {
		if (GameMode->GetIs2D())
			GameMode->ReplaceWidgets(EWidgets::MediumGameMode);
		else {
			GameMode->ClearWidgets();
			UGameplayStatics::OpenLevel(GetWorld(), "Medium3DGame");
		}
	}
}
void UDifficultySelectionWidget::HandleHardButtonClick() {
	if (GameMode) {
		if (GameMode->GetIs2D())
			GameMode->ReplaceWidgets(EWidgets::HardGameMode);
		else {
			GameMode->ClearWidgets();
			UGameplayStatics::OpenLevel(GetWorld(), "Hard3DGame");
		}
	}
}