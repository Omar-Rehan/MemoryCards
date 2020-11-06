#pragma once

#include "CoreMinimal.h"
#include "CardSetManager.h"
#include "WidgetsManager.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
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
		UWidgetsManager* WidgetsManager;
	UPROPERTY()
		UCardSetManager* CardSetManager;

public:
	UPROPERTY()
		uint8 NumOfCards;
	UPROPERTY()
		TEnumAsByte<EWidgets> SelectedDiffculty;
	UPROPERTY(EditAnywhere)
		TMap<TEnumAsByte<EWidgets>, TSubclassOf<UUserWidget>> WidgetClasses;
	UPROPERTY(EditAnywhere)
		TMap<TEnumAsByte<EWidgets>, FName> MapIDs;
	
	UFUNCTION()
		void StartGame(uint8 NumberOfCards);
	UFUNCTION()
		void EndGame(bool bWon);
	UFUNCTION()
		void PlayAgain();


	UFUNCTION()
		void ReplaceMap(TEnumAsByte<EWidgets> WidgetClassName);
	UFUNCTION(BlueprintCallable)
		void ReplaceWidgets(TEnumAsByte<EWidgets> WidgetClassName);
	UFUNCTION()
		void ClearWidgets();
	UFUNCTION()
		void SetNumOfMovesTextBlock(UTextBlock* TextBlock);

	UFUNCTION()
		void InitializeCard(TScriptInterface<ICard> Card);
	UFUNCTION()
		void HandleCardClick(TScriptInterface<ICard> Card);



	/// Game Manager
public:
	void Enable2DMode() {
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		PlayerController->bShowMouseCursor = true;
		PlayerController->SetInputMode(FInputModeUIOnly());
	}
	void Enable3DMode() {
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		PlayerController->bShowMouseCursor = false;
		PlayerController->SetInputMode(FInputModeGameOnly());
	}

	UFUNCTION()
		void SetIs2D(bool is2D) { bIs2D = is2D; }
	UFUNCTION()
		bool GetIs2D() const { return bIs2D; }
protected:
	UPROPERTY()
		bool bIs2D;

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
