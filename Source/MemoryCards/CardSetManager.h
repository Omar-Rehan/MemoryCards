#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "Components/ActorComponent.h"
#include "CardSetManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEMORYCARDS_API UCardSetManager : public UActorComponent {
	GENERATED_BODY()

public:	
	UFUNCTION()
		void Initialize(uint8 NumberOfCards);
	UFUNCTION()
		void InitializeCard(TScriptInterface<ICard> Card);
	UFUNCTION()
		bool HandleCardClick(TScriptInterface<ICard> Card);
	UFUNCTION()
		void DisableAllCards();

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
