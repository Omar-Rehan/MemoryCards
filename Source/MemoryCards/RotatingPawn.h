#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerInput.h"
#include "RotatingPawn.generated.h"

UCLASS()
class MEMORYCARDS_API ARotatingPawn : public APawn {
	GENERATED_BODY()
public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
