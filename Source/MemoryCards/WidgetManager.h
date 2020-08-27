#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/NoExportTypes.h"
#include "WidgetManager.generated.h"

UCLASS()
class MEMORYCARDS_API UWidgetManager : public UObject {
	GENERATED_BODY()
	
public:
	UWidgetManager();

	UFUNCTION()
		void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	UPROPERTY()
		UUserWidget* CurrentWidget;
};
