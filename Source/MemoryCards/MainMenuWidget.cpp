#include "MainMenuWidget.h"

void UMainMenuWidget::Setup(UWorld* WorldReference) {
	GameMode = Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(WorldReference));

	PlayButton->OnClicked.AddDynamic(this, &UMainMenuWidget::HandlePlayButtonClick);
	OptionsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::HandleOptionsButtonClick);
	ExitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::HandleExitButtonClick);
}
void UMainMenuWidget::HandlePlayButtonClick() {
	if (GameMode)
		GameMode->ReplaceWidgets(EWidgets::DifficultySelection);
}
void UMainMenuWidget::HandleOptionsButtonClick() {
	UE_LOG(LogTemp, Warning, TEXT("Options Button Clicked!"));
}
void UMainMenuWidget::HandleExitButtonClick() {
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}