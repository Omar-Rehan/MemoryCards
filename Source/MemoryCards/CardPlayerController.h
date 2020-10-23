#pragma once

#include "CoreMinimal.h"
#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"
#include "MemoryCardsGameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "CardPlayerController.generated.h"

UCLASS()
class MEMORYCARDS_API ACardPlayerController : public APlayerController {
	GENERATED_BODY()
	
	void BeginPlay() override;

public:
	void AttemptCardFlip();
};
