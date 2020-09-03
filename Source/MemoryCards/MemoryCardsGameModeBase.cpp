#include "MemoryCardsGameModeBase.h"

AMemoryCardsGameModeBase::AMemoryCardsGameModeBase() {
	CardSetManager = CreateDefaultSubobject<UCardSetManager>(TEXT("Cards Manager"));
	AddOwnedComponent(CardSetManager);

	ViewportManager = CreateDefaultSubobject<UWidgetsManager>(TEXT("Widgets Manager"));
	AddOwnedComponent(ViewportManager);
}

void AMemoryCardsGameModeBase::BeginPlay() {
	Super::BeginPlay();

	NumOfMoves = 0;
	NumOfMatches = 0;

	if (ViewportManager)
		ViewportManager->ReplaceWidget(StartWidgetClass, GetWorld());
}

void AMemoryCardsGameModeBase::ReplaceWidget(TSubclassOf<UUserWidget> NewWidgetClass) {
	if (ViewportManager)
		ViewportManager->ReplaceWidget(NewWidgetClass, GetWorld());
}

void AMemoryCardsGameModeBase::InitializeCard(TScriptInterface<ICard> Card) {
	if (CardSetManager)
		CardSetManager->InitializeCard(Card);
	else
		UE_LOG(LogTemp, Warning, TEXT("CardSetManager is null in GameMode::InitializeCard"))
}
void AMemoryCardsGameModeBase::OnCardClicked(TScriptInterface<ICard> Card) {
	if (!CardSetManager) {
		UE_LOG(LogTemp, Warning, TEXT("Cards Manager is nullptr"));
		return;
	}
		
	bool bIsMatch = CardSetManager->OnCardClicked(Card);
	NumOfMoves++;
	if (bIsMatch) NumOfMatches++;
	
	UE_LOG(LogTemp, Warning, TEXT("Num of moves: %d"), NumOfMoves);
	UE_LOG(LogTemp, Warning, TEXT("Num of matches: %d"), NumOfMatches);
	
	if (NumOfMovesTextBlock)
		NumOfMovesTextBlock->SetText(FText::FromString(FString("Number of moves: ") + FString::FromInt(NumOfMoves)));

	if (NumOfMatches == NumOfMatchesMax)
		EndGame(true);
	else if (NumOfMoves == NumOfMovesMax)
		EndGame(false);
}

void AMemoryCardsGameModeBase::SetNumOfMovesTextBlock(UTextBlock* TextBlock) {
	if (TextBlock)
		NumOfMovesTextBlock = TextBlock;
}
void AMemoryCardsGameModeBase::SetNumOfCards(uint8 NumberOfCards) {
	NumOfCards = NumberOfCards;
	check(!(NumOfCards & 1));
	
	NumOfMovesMax = NumOfCards << 1;
	NumOfMatchesMax = NumOfCards >> 1;

	if (CardSetManager)
		CardSetManager->Initialize(NumOfCards);
}

void AMemoryCardsGameModeBase::EndGame(bool bWon) {
	if (bWon) {
		UE_LOG(LogTemp, Warning, TEXT("GAME WON"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("GAME LOST"));
		CardSetManager->DisableAllCards();
	}
}