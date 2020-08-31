#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ActorComponent.h"
#include "WidgetsManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEMORYCARDS_API UWidgetsManager : public UActorComponent {
	GENERATED_BODY()

public:
	UWidgetsManager();

	UFUNCTION()
		void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass, UWorld* WorldReference);

protected:
	UPROPERTY()
		UUserWidget* CurrentWidget;
};
