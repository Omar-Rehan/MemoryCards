#include "CardsInitializer.h"

void UCardsInitializer::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("CardsInitializer begin play"));

	Cast<AMemoryCardsGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()))->StartGame(NumberOfCards);
	
	USceneComponent* SceneComponent = GetOwner()->FindComponentByClass<USceneComponent>();
	if (!SceneComponent) {
		UE_LOG(LogTemp, Warning, TEXT("Cannot find scene component"));
		return;
	}

	TArray<USceneComponent*> CardSceneComponents = SceneComponent->GetAttachChildren();
	for (USceneComponent* CardSceneComponent : CardSceneComponents) {
		AActor* CardActor = CardSceneComponent->GetOwner();
		UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *CardActor->GetName());
		
		UCardInfoComponent* CardInfoComponent = CardActor->FindComponentByClass<UCardInfoComponent>();
		if (!CardInfoComponent) {
			UE_LOG(LogTemp, Warning, TEXT("Cannot find card info component"));
			return;
		}

		ICard* Card = Cast<ICard>(CardInfoComponent);
		if (!Card) {
			UE_LOG(LogTemp, Warning, TEXT("Cannot cast to ICard"));
			return;
		}
		
		Card->Initialize();
	}
}