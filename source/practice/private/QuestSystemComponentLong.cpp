// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystemComponentLong.h"

#include "Quest.h"

#include "EngineUtils.h"

// Sets default values for this component's properties
UQuestSystemComponentLong::UQuestSystemComponentLong()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UQuestSystemComponentLong::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<AQuest> It(GetWorld(), AQuest::StaticClass()); It; ++It)
	{
		ActiveQuests.AddUnique(*It);
	}
	for (const TSubclassOf<AQuest>& QuestClass : Quests)
	{
		AQuest* Quest = GetWorld()->SpawnActor<AQuest>(QuestClass);
		ActiveQuests.Add(Quest);
	}
	// ...
	
}

// Called every frame
void UQuestSystemComponentLong::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UQuestSystemComponentLong::GetActiveAndStartedQuests(TArray<AQuest*>& OutQuests)
{
	for (AQuest* Quest : ActiveQuests)
	{
		if (Quest->GetQuestStatus() == EQuestStatus::Started)
		{
			OutQuests.Add(Quest);
		}
	}
}


void UQuestSystemComponentLong::RegisterQuest(AQuest* NewQuest)
{
	ActiveQuests.AddUnique(NewQuest);
}