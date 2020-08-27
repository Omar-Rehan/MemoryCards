#pragma once

#include "CoreMinimal.h"
#include "CardsManager.h"
#include "WidgetManager.h"
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
		TSubclassOf<UUserWidget> InitialWidgetClass;
	
	UFUNCTION()
		void OnCardClicked(TScriptInterface<ICard> Card);
	UFUNCTION()
		int32 GetCardValue(uint8 Index) const;


	/// Game Manager
protected:
	UPROPERTY()
		uint8 NumOfMoves;
};
