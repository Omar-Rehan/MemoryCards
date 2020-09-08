#include "MemoryCardsGameModeBase.h"

AMemoryCardsGameModeBase::AMemoryCardsGameModeBase() {
	CardSetManager = CreateDefaultSubobject<UCardSetManager>(TEXT("Cards Manager"));
	AddOwnedComponent(CardSetManager);

	WidgetManager = CreateDefaultSubobject<UWidgetsManager>(TEXT("Widgets Manager"));
	AddOwnedComponent(WidgetManager);
}

void AMemoryCardsGameModeBase::BeginPlay() {
	Super::BeginPlay();
	if (WidgetManager)
		WidgetManager->ReplaceWidgets(WidgetClasses[EWidgets::MainMenu], GetWorld());
	else
		UE_LOG(LogTemp, Warning, TEXT("WidgetManager is nullified"));
}

void AMemoryCardsGameModeBase::ReplaceWidgets(TEnumAsByte<EWidgets> WidgetClass) {
	if (WidgetManager)
		WidgetManager->ReplaceWidgets(WidgetClasses[WidgetClass], GetWorld());
}

void AMemoryCardsGameModeBase::InitializeCard(TScriptInterface<ICard> Card) {
	if (CardSetManager)
		CardSetManager->InitializeCard(Card);
	else
		UE_LOG(LogTemp, Warning, TEXT("CardSetManager is null in GameMode::InitializeCard"))
}
void AMemoryCardsGameModeBase::HandleCardClick(TScriptInterface<ICard> Card) {
	if (!CardSetManager) {
		UE_LOG(LogTemp, Warning, TEXT("Cards Manager is nullptr"));
		return;
	}
		
	bool bIsMatch = CardSetManager->HandleCardClick(Card);
	NumOfMoves++;
	if (bIsMatch) NumOfMatches++;
		
	if (NumOfMovesTextBlock)
		NumOfMovesTextBlock->SetText(FText::FromString(FString("Number of moves: ") + FString::FromInt(NumOfMoves)));

	if (NumOfMatches == NumOfMatchesMax)
		EndGame(true);
	else if (NumOfMoves == NumOfMovesMax)
		EndGame(false);
}

void AMemoryCardsGameModeBase::StartGame(uint8 NumberOfCards) {
	NumOfCards = NumberOfCards;
	check(!(NumOfCards & 1));
	
	NumOfMoves = 0;
	NumOfMatches = 0;

	NumOfMovesMax = (3 * NumOfCards) >> 1;
	NumOfMatchesMax = NumOfCards >> 1;

	SelectedDiffculty = NumOfCards == 8 ? EasyGameMode : NumOfCards == 16 ? MediumGameMode : HardGameMode;

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

	if (WidgetManager) {
		TEnumAsByte<EWidgets> EndGameWidgetClass = EWidgets::EndGame;
		WidgetManager->AddWidget(WidgetClasses[EWidgets::EndGame], GetWorld());
	}
}

void AMemoryCardsGameModeBase::PlayAgain() {
	if (WidgetManager)
		WidgetManager->ReplaceWidgets(WidgetClasses[SelectedDiffculty], GetWorld());
}

void AMemoryCardsGameModeBase::SetNumOfMovesTextBlock(UTextBlock* TextBlock) {
	if (TextBlock)
		NumOfMovesTextBlock = TextBlock;
}