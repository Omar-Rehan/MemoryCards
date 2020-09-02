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
	UWidgetsManager();

	UFUNCTION()
		void ReplaceWidget(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference);
	UFUNCTION()
		void ChangeWidgetGame(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference);

protected:
	UPROPERTY()
		UUserWidget* CurrentWidget;
};
