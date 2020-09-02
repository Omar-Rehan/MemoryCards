#pragma once

#include "CoreMinimal.h"
#include "CardButton.h"
#include "CustomWidget.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryCardsGameModeBase.h"
#include "InGameWidget.generated.h"

UCLASS()
class MEMORYCARDS_API UInGameWidget : public UUserWidget, public ICustomWidget {
	GENERATED_BODY()
public:
	UFUNCTION()
		virtual void Setup() override final;

protected:
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		UTextBlock* NumberOfMovesTextBlock;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		UCardButton* CardButton_0;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		UCardButton* CardButton_1;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		UCardButton* CardButton_2;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		UCardButton* CardButton_3;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		UCardButton* CardButton_4;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		UCardButton* CardButton_5;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		UCardButton* CardButton_6;
	UPROPERTY(VisibleAnywhere, meta = (BindWidget))
		UCardButton* CardButton_7;
};
