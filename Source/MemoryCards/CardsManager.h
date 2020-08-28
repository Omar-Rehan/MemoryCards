#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "UObject/NoExportTypes.h"
#include "CardsManager.generated.h"

UCLASS()
class MEMORYCARDS_API UCardsManager : public UObject {
	GENERATED_BODY()
	
public:
	UFUNCTION()
		void Initialize(uint8 NumberOfCards);
	UFUNCTION()
		void InitializeCard(TScriptInterface<ICard> Card);
	UFUNCTION()
		void OnCardClicked(TScriptInterface<ICard> Card);

protected:
	uint8 CardSetSize;
	UPROPERTY()
		TArray<int32> CardSetValues;
	UPROPERTY()
		TArray<TScriptInterface<ICard>> CardSet;
	UPROPERTY()
		TScriptInterface<ICard> FlippedCard;

	UFUNCTION()
		void InitializeCardSetValues();
};
