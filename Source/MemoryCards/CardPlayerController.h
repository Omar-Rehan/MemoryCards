#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CardPlayerController.generated.h"

UCLASS()
class MEMORYCARDS_API ACardPlayerController : public APlayerController {
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
};
