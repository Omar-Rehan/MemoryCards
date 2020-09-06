#pragma once

#include "CoreMinimal.h"
#include "CustomWidget.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryCardsGameModeBase.h"
#include "GameEndWidget.generated.h"

UCLASS()
class MEMORYCARDS_API UGameEndWidget : public UUserWidget, public ICustomWidget {
	GENERATED_BODY()
public:
	virtual void Setup(UWorld* WorldReference) override final;

protected:
	UPROPERTY()
		AMemoryCardsGameModeBase* GameMode;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UButton* PlayAgainButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UButton* ReturnToMenuButton;

	UFUNCTION()
		void HandlePlayAgainButtonClick();
	UFUNCTION()
		void HandleReturnToMenuButtonClick();
};
