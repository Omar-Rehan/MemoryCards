#include "WidgetsManager.h"

UWidgetsManager::UWidgetsManager() {
	CurrentWidget = nullptr;
}

void UWidgetsManager::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference) {
	UE_LOG(LogTemp, Warning, TEXT("ChangeWidget called"))
		if (CurrentWidget) {
			CurrentWidget->RemoveFromViewport();
			CurrentWidget = nullptr;
		}

	if (NewWidgetClass) {
		UE_LOG(LogTemp, Warning, TEXT("New widget class is valid"));

		CurrentWidget = CreateWidget<UUserWidget>(WorldReference, NewWidgetClass);
		if (CurrentWidget) {
			CurrentWidget->AddToViewport();
			UE_LOG(LogTemp, Warning, TEXT("New widget creation succeeded"))
		} 
		else
			UE_LOG(LogTemp, Error, TEXT("New widget creation failed"))
	}
}