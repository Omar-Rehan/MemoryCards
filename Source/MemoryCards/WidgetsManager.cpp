#include "WidgetsManager.h"
#include "InGameWidget.h"

UWidgetsManager::UWidgetsManager() {
	CurrentWidget = nullptr;
}

void UWidgetsManager::ReplaceWidget(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference) {
	if (CurrentWidget) {
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass) {
		CurrentWidget = CreateWidget<UUserWidget>(WorldReference, NewWidgetClass);
		if (CurrentWidget)
			CurrentWidget->AddToViewport();
	}
}
void UWidgetsManager::ChangeWidgetGame(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference) {
	if (CurrentWidget) {
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass) {
		CurrentWidget = CreateWidget(WorldReference, NewWidgetClass);
		if (CurrentWidget) {
			CurrentWidget->AddToViewport();
			
			UInGameWidget* GameWidget = Cast<UInGameWidget>(CurrentWidget);
			if (GameWidget) {
				UE_LOG(LogTemp, Warning, TEXT("Cast succeeded"));
				GameWidget->Setup();
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Cast failed"));
			}
		}
	}
}