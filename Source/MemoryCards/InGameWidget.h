#pragma once

#include "CoreMinimal.h"
#include "CardButton.h"
#include "CustomWidget.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryCardsGameModeBase.h"
#include "Components/UniformGridPanel.h"
#include "InGameWidget.generated.h"

UCLASS()
class MEMORYCARDS_API UInGameWidget : public UUserWidget, public ICustomWidget {
	GENERATED_BODY()
public:
	UFUNCTION()
		virtual void Setup(UWorld* WorldReference) override final;

protected:
	UPROPERTY()
		AMemoryCardsGameModeBase* GameMode;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UTextBlock* NumberOfMovesTextBlock;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UUniformGridPanel* CardsGrid;

	UPROPERTY()
		TArray<UCardButton*> CardButtons;
};
