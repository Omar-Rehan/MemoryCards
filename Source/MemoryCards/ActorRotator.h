#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "ActorRotator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEMORYCARDS_API UActorRotator : public UActorComponent {
	GENERATED_BODY()

public:
	void Rotate(float angle = 180.0f);
};
