#pragma once

#include "CoreMinimal.h"
#include "CustomWidget.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryCardsGameModeBase.h"
#include "DifficultySelectionWidget.generated.h"

UCLASS()
class MEMORYCARDS_API UDifficultySelectionWidget : public UUserWidget, public ICustomWidget {
	GENERATED_BODY()
public:
	virtual void Setup(UWorld* WorldReference) override final;

protected:
	UPROPERTY()
		AMemoryCardsGameModeBase* GameMode;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UButton* EasyButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UButton* MediumButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UButton* HardButton;

	UFUNCTION()
		void HandleEasyButtonClick();
	UFUNCTION()
		void HandleMediumButtonClick();
	UFUNCTION()
		void HandleHardButtonClick();
};
