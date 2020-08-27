#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "UObject/NoExportTypes.h"
#include "CardsManager.generated.h"

UCLASS()
class MEMORYCARDS_API UCardsManager : public UObject {
	GENERATED_BODY()

	UCardsManager();
	
public:
	UFUNCTION()
		void InitializeCardSet();
	UFUNCTION()
		int32 GetCardValue(uint8 Index) const;
	UFUNCTION()
		void OnCardClicked(TScriptInterface<ICard> Card);

protected:
	UPROPERTY()
		uint16 CardSetSize;
	UPROPERTY()
		TArray<int32> CardSetValues;
	UPROPERTY()
		TArray<TScriptInterface<ICard>> FlippedCards;

	UFUNCTION()
		bool IsMatch();
};
