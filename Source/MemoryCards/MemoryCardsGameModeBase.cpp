#include "MemoryCardsGameModeBase.h"

AMemoryCardsGameModeBase::AMemoryCardsGameModeBase() {
	GameWidgetClass = nullptr; // to be changed from the editor
}

void AMemoryCardsGameModeBase::BeginPlay() {
	Super::BeginPlay();

	WidgetManager = NewObject<UWidgetManager>();
	if (WidgetManager)
		UE_LOG(LogTemp, Warning, TEXT("WidgetManager creation successful"))
	else
		UE_LOG(LogTemp, Warning, TEXT("WidgetManager creation failed"));

	CardsManager = NewObject<UCardsManager>();
	if (CardsManager)
		UE_LOG(LogTemp, Warning, TEXT("CardsManager creation successful"))
	else
		UE_LOG(LogTemp, Warning, TEXT("CardsManager creation failed"));



	if (WidgetManager)
		WidgetManager->ChangeWidget(GameWidgetClass, GetWorld());
	else
		UE_LOG(LogTemp, Warning, TEXT("WidgetManager is null in GameMode::BeginPlay"))

	if (CardsManager)
		CardsManager->Initialize(8);
	else
		UE_LOG(LogTemp, Warning, TEXT("CardsManager is null in GameMode::BeginPlay"))


	NumOfMoves = 0;
}

void AMemoryCardsGameModeBase::OnCardClicked(TScriptInterface<ICard> Card) {
	if (CardsManager)
		CardsManager->OnCardClicked(Card);
	else
		UE_LOG(LogTemp, Warning, TEXT("CardsManager is null in OnCardClicked"))
	
	if (NumOfMovesTextBlock)
		NumOfMovesTextBlock->SetText(FText::FromString(FString("Number of moves: ") + FString::FromInt(++NumOfMoves)));
}
void AMemoryCardsGameModeBase::InitializeCard(TScriptInterface<ICard> Card) {
	if (CardsManager)
		CardsManager->InitializeCard(Card);
	else
		UE_LOG(LogTemp, Warning, TEXT("CardsManager is null in GameMode::InitializeCard"))
}

void AMemoryCardsGameModeBase::SetNumOfMovesTextBlock(UTextBlock* TextBlock) {
	if (TextBlock) 
		NumOfMovesTextBlock = TextBlock;
}