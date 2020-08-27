#include "WidgetManager.h"

UWidgetManager::UWidgetManager() {
	CurrentWidget = nullptr;
}

void UWidgetManager::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass) {
	if (CurrentWidget) {
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass) {
		CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);
		if (CurrentWidget) CurrentWidget->AddToViewport();
	}
}