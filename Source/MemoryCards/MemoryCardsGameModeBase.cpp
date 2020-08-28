#include "MemoryCardsGameModeBase.h"

AMemoryCardsGameModeBase::AMemoryCardsGameModeBase() {
	InitialWidgetClass = nullptr; // to be changed from the editor
	WidgetManager = CreateDefaultSubobject<UWidgetManager>(TEXT("Widget Manager"));
	CardsManager = CreateDefaultSubobject<UCardsManager>(TEXT("Cards Manager"));
}

void AMemoryCardsGameModeBase::BeginPlay() {
	Super::BeginPlay();
	WidgetManager->ChangeWidget(InitialWidgetClass);
	CardsManager->Initialize(8);
	NumOfMoves = 0;
}

void AMemoryCardsGameModeBase::OnCardClicked(TScriptInterface<ICard> Card) {
	CardsManager->OnCardClicked(Card);
	
	if (ScoreTextBlock)
		ScoreTextBlock->SetText(FText::FromString(FString("Number of moves: ") + FString::FromInt(++NumOfMoves)));
}
void AMemoryCardsGameModeBase::InitializeCard(TScriptInterface<ICard> Card) {
	CardsManager->InitializeCard(Card);
}

void AMemoryCardsGameModeBase::SetScoreTextBlock(UScoreTextBlock* TextBlock) {
	if (TextBlock) 
		ScoreTextBlock = TextBlock;
}