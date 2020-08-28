#pragma once

#include "CoreMinimal.h"
#include "CardsManager.h"
#include "WidgetManager.h"
#include "ScoreTextBlock.h"
#include "GameFramework/GameModeBase.h"
#include "MemoryCardsGameModeBase.generated.h"

UCLASS()
class MEMORYCARDS_API AMemoryCardsGameModeBase : public AGameModeBase {
	GENERATED_BODY()

	AMemoryCardsGameModeBase();
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UWidgetManager* WidgetManager;
	UPROPERTY(EditAnywhere)
		UCardsManager* CardsManager;

public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> InitialWidgetClass;
	
	UFUNCTION()
		void InitializeCard(TScriptInterface<ICard> Card);
	UFUNCTION()
		void OnCardClicked(TScriptInterface<ICard> Card);
	UFUNCTION(BlueprintCallable)
		void SetScoreTextBlock(UScoreTextBlock* TextBlock);


	/// Game Manager
protected:
	UPROPERTY()
		uint8 NumOfMoves;
	UPROPERTY()
		UScoreTextBlock* ScoreTextBlock;
};
