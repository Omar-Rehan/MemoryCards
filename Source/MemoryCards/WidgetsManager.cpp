#include "WidgetsManager.h"

void UWidgetsManager::ReplaceWidgets(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference) {
	ClearWidgets();
	AddWidget(NewWidgetClass, WorldReference);
}
void UWidgetsManager::AddWidget(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference) {
	if (!NewWidgetClass) return;
	
	UUserWidget* NewWidget = CreateWidget<UUserWidget>(WorldReference, NewWidgetClass);
	if (NewWidget) {
		NewWidget->AddToViewport();
		CurrentWidgets.Add(NewWidget);

		ICustomWidget* CustomWidget = Cast<ICustomWidget>(NewWidget);
		if (CustomWidget) 
			CustomWidget->Setup(WorldReference);
	}
}
void UWidgetsManager::RemoveWidget(TSubclassOf<UUserWidget> WidgetClass) {
	if (!WidgetClass) return;

	for (int32 Index = 0 ; Index < CurrentWidgets.Num(); Index++) {
		UUserWidget* Widget = CurrentWidgets[Index];
		if (WidgetClass == Widget->StaticClass()) {
			Widget->RemoveFromViewport();
			CurrentWidgets.RemoveAt(Index--);
			Widget = nullptr;
		}
	}
}

void UWidgetsManager::ClearWidgets() {
	for (auto Widget : CurrentWidgets) {
		Widget->RemoveFromViewport();
		Widget = nullptr;
	}
	CurrentWidgets.Empty();
}