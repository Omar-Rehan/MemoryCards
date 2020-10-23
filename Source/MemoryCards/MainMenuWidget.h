#pragma once

#include "CoreMinimal.h"
#include "CustomWidget.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryCardsGameModeBase.h"
#include "MainMenuWidget.generated.h"

UCLASS()
class MEMORYCARDS_API UMainMenuWidget : public UUserWidget, public ICustomWidget {
	GENERATED_BODY()
public:
	virtual void Setup(UWorld* WorldReference) override final;

protected:
	UPROPERTY()
		AMemoryCardsGameModeBase* GameMode;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UButton* Play2DButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UButton* Play3DButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UButton* OptionsButton;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
		UButton* ExitButton;

	UFUNCTION()
		void HandlePlay2DButtonClick();
	UFUNCTION()
		void HandlePlay3DButtonClick();
	UFUNCTION()
		void HandleOptionsButtonClick();
	UFUNCTION()
		void HandleExitButtonClick();
};
