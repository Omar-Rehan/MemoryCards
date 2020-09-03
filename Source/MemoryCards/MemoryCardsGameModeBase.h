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
		UWidgetsManager* ViewportManager;
	UPROPERTY()
		UCardSetManager* CardSetManager;

public:
	UPROPERTY()
		uint8 NumOfCards;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> StartWidgetClass;
	
	UFUNCTION(BlueprintCallable)
		void ReplaceWidget(TSubclassOf<UUserWidget> NewWidgetClass);
	UFUNCTION(BlueprintCallable)
		void SetNumOfCards(uint8 NumberOfCards);
	UFUNCTION()
		void InitializeCard(TScriptInterface<ICard> Card);
	UFUNCTION()
		void OnCardClicked(TScriptInterface<ICard> Card);
	UFUNCTION()
		void SetNumOfMovesTextBlock(UTextBlock* TextBlock);


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
