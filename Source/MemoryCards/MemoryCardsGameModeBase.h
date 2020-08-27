#pragma once

#include "Card.h"
#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/KismetArrayLibrary.h"
#include "GameFramework/GameModeBase.h"
#include "MemoryCardsGameModeBase.generated.h"

UCLASS()
class MEMORYCARDS_API AMemoryCardsGameModeBase : public AGameModeBase {
	GENERATED_BODY()

	AMemoryCardsGameModeBase();
	virtual void BeginPlay() override;

	#pragma region Widget Members
public:
	UFUNCTION()
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> InitialWidgetClass;
	UPROPERTY()
		UUserWidget* CurrentWidget;
#pragma endregion
	
	#pragma region Card Members
public:
	UFUNCTION()
		int32 GetCardValue(uint16 Index) const;
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
		void InitializeCardSet();
	UFUNCTION()
		bool IsMatch();
	#pragma endregion

	UPROPERTY()
		uint8 NumOfMoves;
};
