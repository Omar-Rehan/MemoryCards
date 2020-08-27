#pragma once

#include "Card.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UCard : public UInterface {
    GENERATED_BODY()
};

class ICard {
    GENERATED_BODY()

public:
	UFUNCTION()
		virtual void Flip() = 0;
	UFUNCTION()
		virtual void Disable() = 0;
	UFUNCTION()
		virtual int32 GetValue() = 0;
	UFUNCTION()
		virtual void HandleClick() = 0;
};