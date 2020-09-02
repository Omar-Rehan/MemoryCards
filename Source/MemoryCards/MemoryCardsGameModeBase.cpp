#include "MemoryCardsGameModeBase.h"

AMemoryCardsGameModeBase::AMemoryCardsGameModeBase() {
	GameWidgetClass = nullptr; // to be changed from the editor

	CardSetManager = CreateDefaultSubobject<UCardSetManager>(TEXT("Cards Manager"));
	AddOwnedComponent(CardSetManager);

	WidgetsManager = CreateDefaultSubobject<UWidgetsManager>(TEXT("Widgets Manager"));
	AddOwnedComponent(WidgetsManager);
}

void AMemoryCardsGameModeBase::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("GameMode BeginPlay"));

	NumOfMoves = 0;
	NumOfMatches = 0;

	NumOfCards = 8; // TODO: make the user choose
	check(!(NumOfCards & 1));
	NumOfMovesMax = NumOfCards << 1;
	NumOfMatchesMax = NumOfCards >> 1;

	if (CardSetManager)
		CardSetManager->Initialize(NumOfCards);
	else
		UE_LOG(LogTemp, Warning, TEXT("CardSetManager is null in GameMode::BeginPlay"))

	if (WidgetsManager)
		WidgetsManager->ReplaceWidget(MenuWidgetClass, GetWorld());
	else
		UE_LOG(LogTemp, Warning, TEXT("WidgetsManager is null in GameMode::BeginPlay"))
}

void AMemoryCardsGameModeBase::StartGame() {
	if (WidgetsManager) {
		WidgetsManager->ChangeWidgetGame(GameWidgetClass, GetWorld());
		//WidgetsManager->SetupInGameWidget();
	}
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

void AMemoryCardsGameModeBase::SetNumOfCards(uint8 NumberOfCards) {
	NumOfCards = NumberOfCards;
}
void AMemoryCardsGameModeBase::SetNumOfMovesTextBlock(UTextBlock* TextBlock) {
	if (TextBlock) 
		NumOfMovesTextBlock = TextBlock;
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