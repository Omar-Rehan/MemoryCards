#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/ContentWidget.h"
#include "CardWidget.generated.h"

UCLASS()
class MEMORYCARDS_API UCardWidget : public UContentWidget {
	GENERATED_BODY()
	
public:
	UCardWidget();

protected:
	UPROPERTY(VisibleAnywhere)
		UButton* Button;
	UPROPERTY(VisibleAnywhere)
		UTextBlock* TextBlock;
};
