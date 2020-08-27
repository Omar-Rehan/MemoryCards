#include "MemoryCardsGameModeBase.h"

AMemoryCardsGameModeBase::AMemoryCardsGameModeBase() {
	InitialWidgetClass = nullptr; // to be changed from the editor
	WidgetManager = CreateDefaultSubobject<UWidgetManager>(TEXT("Widget Manager"));
	CardsManager = CreateDefaultSubobject<UCardsManager>(TEXT("Cards Manager"));
}

void AMemoryCardsGameModeBase::BeginPlay() {
	Super::BeginPlay();
	WidgetManager->ChangeWidget(InitialWidgetClass);
	CardsManager->InitializeCardSet();
}

void AMemoryCardsGameModeBase::OnCardClicked(TScriptInterface<ICard> Card) {
	CardsManager->OnCardClicked(Card);
}
int32 AMemoryCardsGameModeBase::GetCardValue(uint8 Index) const {
	return CardsManager->GetCardValue(Index);
}