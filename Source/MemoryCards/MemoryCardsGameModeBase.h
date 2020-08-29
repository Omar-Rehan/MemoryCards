#pragma once

#include "CoreMinimal.h"
#include "CardsManager.h"
#include "WidgetManager.h"
#include "Components/TextBlock.h"
#include "GameFramework/GameModeBase.h"
#include "MemoryCardsGameModeBase.generated.h"

UCLASS()
class MEMORYCARDS_API AMemoryCardsGameModeBase : public AGameModeBase {
	GENERATED_BODY()

	AMemoryCardsGameModeBase();
	
	virtual void BeginPlay() override;

	UPROPERTY()
		UWidgetManager* WidgetManager;
	UPROPERTY()
		UCardsManager* CardsManager;

public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> GameWidgetClass;
	
	UFUNCTION()
		void InitializeCard(TScriptInterface<ICard> Card);
	UFUNCTION()
		void OnCardClicked(TScriptInterface<ICard> Card);
	UFUNCTION(BlueprintCallable)
		void SetNumOfMovesTextBlock(UTextBlock* TextBlock);


	/// Game Manager
protected:
	UPROPERTY()
		uint8 NumOfMoves;
	UPROPERTY()
		UTextBlock* NumOfMovesTextBlock;
};
