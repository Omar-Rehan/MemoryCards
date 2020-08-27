#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryCardsGameModeBase.h"
#include "DummyButton.generated.h"

UCLASS()
class MEMORYCARDS_API UDummyButton : public UButton, public ICard {
	GENERATED_BODY()
	
public:
	UDummyButton();
	
	UFUNCTION()
		virtual void Flip() override final;
	UFUNCTION()
		virtual void Disable() override final;
	UFUNCTION()
		virtual int32 GetValue() override final;
	UFUNCTION()
		virtual void HandleClick() override final;

protected:
	static AMemoryCardsGameModeBase* CurrentGameMode;

	UPROPERTY(EditAnywhere)
		uint8 Index;
	UPROPERTY(VisibleAnywhere)
		int32 Value;
	UPROPERTY(VisibleAnywhere)
		bool bHidden;

	UPROPERTY(EditAnywhere)
		UTextBlock* TextBlock;
	void UpdateText();
};
