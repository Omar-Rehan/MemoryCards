#pragma once

#include "CoreMinimal.h"
#include "CardSetManager.h"
#include "WidgetsManager.h"
#include "Components/TextBlock.h"
#include "GameFramework/GameModeBase.h"
#include "MemoryCardsGameModeBase.generated.h"

UCLASS()
class MEMORYCARDS_API AMemoryCardsGameModeBase : public AGameModeBase {
	GENERATED_BODY()

	AMemoryCardsGameModeBase();
	
	virtual void BeginPlay() override;

	UPROPERTY()
		UWidgetsManager* WidgetsManager;
	UPROPERTY()
		UCardSetManager* CardSetManager;

public:
	UPROPERTY()
		uint8 NumOfCards;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> GameWidgetClass;
	
	UFUNCTION(BlueprintCallable)
		void InitializeCard(TScriptInterface<ICard> Card);
	UFUNCTION()
		void OnCardClicked(TScriptInterface<ICard> Card);
	UFUNCTION(BlueprintCallable)
		void SetNumOfMovesTextBlock(UTextBlock* TextBlock);
	UFUNCTION()
		void SetNumOfCards(uint8 NumberOfCards);


	/// Game Manager
protected:
	UPROPERTY()
		uint8 NumOfMatches;
	UPROPERTY()
		uint8 NumOfMatchesMax;
	
	UPROPERTY()
		uint8 NumOfMoves;
	UPROPERTY()
		uint8 NumOfMovesMax;
	UPROPERTY()
		UTextBlock* NumOfMovesTextBlock;

	UFUNCTION()
		void EndGame(bool bWon);
};
