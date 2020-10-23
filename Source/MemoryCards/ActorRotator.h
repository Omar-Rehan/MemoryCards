#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorRotator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MEMORYCARDS_API UActorRotator : public UActorComponent {
	GENERATED_BODY()

public:	
	UActorRotator();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void RotateActor(float angle = 180.0f);
};
