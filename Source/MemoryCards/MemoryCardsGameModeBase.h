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
	/*UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> MainMenuWidgetClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> SelectDifficultyWidgetClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> EasyInGameWidgetClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> MediumInGameWidgetClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> HardInGameWidgetClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> EndGameWidgetClass;*/
	
	UFUNCTION(BlueprintCallable)
		void ReplaceWidgets(TEnumAsByte<EWidgets> WidgetClassName);
	UFUNCTION()
		void SetNumOfCards(uint8 NumberOfCards);
	UFUNCTION()
		void InitializeCard(TScriptInterface<ICard> Card);
	UFUNCTION()
		void OnCardClicked(TScriptInterface<ICard> Card);
	UFUNCTION()
		void SetNumOfMovesTextBlock(UTextBlock* TextBlock);

	UFUNCTION(BlueprintNativeEvent)
		void EndGame(bool bWon);
	void EndGame_Implementation(bool bWon);

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

};
