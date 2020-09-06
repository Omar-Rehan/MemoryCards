#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CustomWidget.generated.h"

UINTERFACE(MinimalAPI)
class UCustomWidget : public UInterface {
	GENERATED_BODY()
};

class MEMORYCARDS_API ICustomWidget {
	GENERATED_BODY()
public:
	UFUNCTION()
		virtual void Setup(UWorld* WorldReference) = 0;
};
