#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryCardsGameModeBase.h"
#include "CardButton.generated.h"

UCLASS()
class MEMORYCARDS_API UCardButton : public UButton, public ICard {
	GENERATED_BODY()
public:
	UCardButton();

	UFUNCTION()
		void Initialize();

	UFUNCTION()
		virtual void Flip() override final;
	UFUNCTION()
		virtual void Disable() override final;
	UFUNCTION()
		virtual void HandleClick() override final;

	UFUNCTION()
		virtual int32 GetValue() override final;
	UFUNCTION()
		virtual void SetValue(int32 NewValue) override final;

	UFUNCTION()
		virtual uint8 GetIndex() override final;
	UFUNCTION()
		virtual void SetIndex(uint8 NewIndex) override final;

protected:
	UPROPERTY()
		AMemoryCardsGameModeBase* CurrentGameMode;

	UPROPERTY(VisibleAnywhere)
		uint8 Index;
	UPROPERTY(VisibleAnywhere)
		int32 Value;
	UPROPERTY(VisibleAnywhere)
		bool bHidden;

	UPROPERTY(EditAnywhere)
		UTextBlock* TextBlock;
	void UpdateText();
};
