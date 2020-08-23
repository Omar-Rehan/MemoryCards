#include "MemoryCardsGameModeBase.h"

AMemoryCardsGameModeBase::AMemoryCardsGameModeBase() {
	CurrentWidget = nullptr;
	InitialWidgetClass = nullptr; // to be changed from the editor
}

void AMemoryCardsGameModeBase::BeginPlay() {
	Super::BeginPlay();
	ChangeMenuWidget(InitialWidgetClass);
	InitializeCardSet();
}

void AMemoryCardsGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass) {
	if (CurrentWidget) {
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (NewWidgetClass) {
		CurrentWidget = CreateWidget(GetWorld(), NewWidgetClass);
		if (CurrentWidget) CurrentWidget->AddToViewport();
	}
}

void AMemoryCardsGameModeBase::InitializeCardSet() {
	CardSetSize = 8; // TODO: find a automated way to do it

	for (int32 i = 1; i <= CardSetSize; i++) {
		CardSet.Add(i);
		CardSet.Add(i);
	}
	for (int32 i = 0; i < 40; i++) {
		int32 Index1 = FMath::RandRange(0, CardSetSize - 1);
		int32 Index2 = FMath::RandRange(0, CardSetSize - 1);
		CardSet.Swap(Index1, Index2);
	}
}
int32 AMemoryCardsGameModeBase::GetCardValue(uint16 Index) const {
	if (Index < CardSetSize)
		return CardSet.GetData()[Index];
	return -1;
}