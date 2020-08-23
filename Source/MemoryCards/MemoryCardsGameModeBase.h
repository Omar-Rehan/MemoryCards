#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/KismetArrayLibrary.h"
#include "GameFramework/GameModeBase.h"
#include "MemoryCardsGameModeBase.generated.h"

UCLASS()
class MEMORYCARDS_API AMemoryCardsGameModeBase : public AGameModeBase {
	GENERATED_BODY()

public:
	AMemoryCardsGameModeBase();

	UFUNCTION()
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
	
	UFUNCTION()
		int32 GetCardValue(uint16 Index) const;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY()
		uint16 CardSetSize;
	UPROPERTY()
		TArray<int32> CardSet;
	UFUNCTION()
		void InitializeCardSet();

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> InitialWidgetClass;
	UPROPERTY()
		UUserWidget* CurrentWidget;
};
