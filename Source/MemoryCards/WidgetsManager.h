#pragma once

#include "CoreMinimal.h"
#include "CustomWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/ActorComponent.h"
#include "WidgetsManager.generated.h"

class UInGameWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEMORYCARDS_API UWidgetsManager : public UActorComponent {
	GENERATED_BODY()
public:
	UFUNCTION()
		void ReplaceWidgets(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference);
	UFUNCTION(BlueprintCallable)
		void AddWidget(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference);
	UFUNCTION()
		void RemoveWidget(TSubclassOf<UUserWidget> WidgetClass);
	UFUNCTION()
		void ClearWidgets();

protected:
	UPROPERTY()
		TArray<UUserWidget*> CurrentWidgets;
};
