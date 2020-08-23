#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryCardsGameModeBase.h"
#include "DummyButton.generated.h"

UCLASS()
class MEMORYCARDS_API UDummyButton : public UButton {
	GENERATED_BODY()
	
public:
	UDummyButton();
	UFUNCTION()
		void HandleClick();

protected:
	UPROPERTY(EditAnywhere)
		uint8 Index;
	UPROPERTY(VisibleAnywhere)
		int32 Value;
	UPROPERTY(VisibleAnywhere)
		bool bHidden;

	UPROPERTY(EditAnywhere)
		UTextBlock* TextBlock;
	void FlipCard();
	void UpdateText();
};
