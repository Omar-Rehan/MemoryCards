#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "ActorRotator.h"
#include "Materials/Material.h"
#include "MemoryCardsGameModeBase.h"
#include "Components/ActorComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "CardInfoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEMORYCARDS_API UCardInfoComponent : public UActorComponent, public ICard {
	GENERATED_BODY()

public:	
	UCardInfoComponent();

	UFUNCTION()
		virtual void Initialize() override final;

	UFUNCTION()
		virtual void RequestFlip(bool bDelayed) override final;
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
		AMemoryCardsGameModeBase* GameMode;

	UPROPERTY(VisibleAnywhere)
		uint8 Index;
	UPROPERTY(VisibleAnywhere)
		int32 Value;
	UPROPERTY(VisibleAnywhere)
		bool bHidden;
	UPROPERTY()
		bool bBusy;

	void UpdateDisplay();
};
