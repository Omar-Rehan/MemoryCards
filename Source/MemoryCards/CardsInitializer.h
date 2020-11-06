#pragma once

#include "CoreMinimal.h"
#include "Card.h"
#include "CardInfoComponent.h"
#include "GameFramework/Actor.h"
#include "MemoryCardsGameModeBase.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "CardsInitializer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEMORYCARDS_API UCardsInitializer : public UActorComponent {
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	uint8 NumberOfCards = 8; // TODO: find a better way to determine num of cards
};
