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
	NumOfMoves = 0;
}

void AMemoryCardsGameModeBase::OnCardClicked(TScriptInterface<ICard> Card) {
	CardsManager->OnCardClicked(Card);
	if (ScoreTextBlock)
		ScoreTextBlock->SetText(FText::FromString(FString("Number of moves: ") + FString::FromInt(++NumOfMoves)));
}
int32 AMemoryCardsGameModeBase::GetCardValue(uint8 Index) const {
	return CardsManager->GetCardValue(Index);
}

void AMemoryCardsGameModeBase::SetScoreTextBlock(UScoreTextBlock* TextBlock) {
	if (TextBlock)
		ScoreTextBlock = TextBlock;
	UE_LOG(LogTemp, Warning, TEXT("Score Text Block received"));
}