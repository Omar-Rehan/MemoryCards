#include "MainMenuWidget.h"

void UMainMenuWidget::Setup(UWorld* WorldReference) {
	GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(WorldReference));

	Play2DButton->OnClicked.AddDynamic(this, &UMainMenuWidget::HandlePlay2DButtonClick);
	Play3DButton->OnClicked.AddDynamic(this, &UMainMenuWidget::HandlePlay3DButtonClick);
	OptionsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::HandleOptionsButtonClick);
	ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::HandleExitButtonClick);
}
void UMainMenuWidget::HandlePlay2DButtonClick() {
	if (GameMode) {
		GameMode->SetIs2D(true);
		GameMode->ReplaceWidgets(EWidgets::DifficultySelection);
	}
}
void UMainMenuWidget::HandlePlay3DButtonClick() {
	if (GameMode) {
		GameMode->SetIs2D(false);
		GameMode->ReplaceWidgets(EWidgets::DifficultySelection);
	}
}
void UMainMenuWidget::HandleOptionsButtonClick() {
	UE_LOG(LogTemp, Warning, TEXT("Options Button Clicked!"));
}
void UMainMenuWidget::HandleExitButtonClick() {
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}