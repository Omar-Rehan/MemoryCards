#pragma once

#include "CoreMinimal.h"
#include "CardSetManager.h"
#include "WidgetsManager.h"
#include "Components/TextBlock.h"
#include "GameFramework/GameModeBase.h"
#include "MemoryCardsGameModeBase.generated.h"

UENUM()
enum EWidgets {
	MainMenu, DifficultySelection, EasyGameMode, MediumGameMode, HardGameMode, EndGame
};

UCLASS()
class MEMORYCARDS_API AMemoryCardsGameModeBase : public AGameModeBase {
	GENERATED_BODY()

	AMemoryCardsGameModeBase();
	
	virtual void BeginPlay() override;

	UPROPERTY()
		UWidgetsManager* WidgetManager;
	UPROPERTY()
		UCardSetManager* CardSetManager;

public:
	UPROPERTY()
		uint8 NumOfCards;
	UPROPERTY(EditAnywhere)
		TMap<TEnumAsByte<EWidgets>, TSubclassOf<UUserWidget>> WidgetClasses;
	
	UFUNCTION()
		void StartGame(uint8 NumberOfCards);
	UFUNCTION()
		void EndGame(bool bWon);
	UFUNCTION()
		void PlayAgain();

	UFUNCTION(BlueprintCallable)
		void ReplaceWidgets(TEnumAsByte<EWidgets> WidgetClassName);
	UFUNCTION()
		void SetNumOfMovesTextBlock(UTextBlock* TextBlock);

	UFUNCTION()
		void InitializeCard(TScriptInterface<ICard> Card);
	UFUNCTION()
		void HandleCardClick(TScriptInterface<ICard> Card);

	/// Game Manager
protected:
	UPROPERTY()
		TEnumAsByte<EWidgets> SelectedDiffculty;

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

};
