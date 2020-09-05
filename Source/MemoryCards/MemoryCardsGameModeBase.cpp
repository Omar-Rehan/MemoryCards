#include "MemoryCardsGameModeBase.h"

AMemoryCardsGameModeBase::AMemoryCardsGameModeBase() {
	CardSetManager = CreateDefaultSubobject<UCardSetManager>(TEXT("Cards Manager"));
	AddOwnedComponent(CardSetManager);

	WidgetManager = CreateDefaultSubobject<UWidgetsManager>(TEXT("Widgets Manager"));
	AddOwnedComponent(WidgetManager);

	//WidgetClasses.Emplace("Main Menu", NULL);
	//WidgetClasses.Emplace("Difficulty Selection", NULL);
	//WidgetClasses.Emplace("Easy Mode", NULL);
	//WidgetClasses.Emplace("Medium Mode", NULL);
	//WidgetClasses.Emplace("Hard Mode", NULL);
	//WidgetClasses.Emplace("End Game", NULL);
}

void AMemoryCardsGameModeBase::BeginPlay() {
	Super::BeginPlay();

	NumOfMoves = 0;
	NumOfMatches = 0;

	if (WidgetManager)
		WidgetManager->ReplaceWidgets(WidgetClasses[EWidgets::MainMenu], GetWorld());
	else
		UE_LOG(LogTemp, Warning, TEXT("WidgetManager is nullified"));
}

void AMemoryCardsGameModeBase::ReplaceWidgets(TEnumAsByte<EWidgets> WidgetClass) {
	if (WidgetManager) {
		if (WidgetClasses.Contains(WidgetClass))
			WidgetManager->ReplaceWidgets(WidgetClasses[WidgetClass], GetWorld());
		else {
			FString EnumAsString = UEnum::GetValueAsString(WidgetClass.GetValue());
			UE_LOG(LogTemp, Warning, TEXT("There is no WidgetClass with the key %s"), *EnumAsString);
		}
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

void AMemoryCardsGameModeBase::EndGame_Implementation(bool bWon) {
	if (bWon) {
		UE_LOG(LogTemp, Warning, TEXT("GAME WON"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("GAME LOST"));
		CardSetManager->DisableAllCards();
	}
}