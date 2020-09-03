#include "WidgetsManager.h"

void UWidgetsManager::ReplaceWidget(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference) {
	if (CurrentWidget) {
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass) {
		CurrentWidget = CreateWidget<UUserWidget>(WorldReference, NewWidgetClass);
		if (CurrentWidget) {
			CurrentWidget->AddToViewport();

			ICustomWidget* GameWidget = Cast<ICustomWidget>(CurrentWidget);
			if (GameWidget)
				GameWidget->Setup();
		}
	}
}