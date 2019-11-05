// Fill out your copyright notice in the Description page of Project Settings.

#include "LobbyGameMode.h"

#include "Public/TimerManager.h"
#include "Engine/World.h"

#include "MenuProjectGameInstance.h"



void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	++NumberOfPlayers;
	if (NumberOfPlayers >= 1)
	{
		GetWorldTimerManager().SetTimer(GetStartTimer, this, &ALobbyGameMode::StartGame, 10);
		
	}
}

void ALobbyGameMode::Logout(APlayerController* Exiting)
{
	Super::Logout(Exiting);
	--NumberOfPlayers;
}

void ALobbyGameMode::StartGame()
{
	auto GameInstance = Cast <UMenuProjectGameInstance>(GetGameInstance());

	if (GameInstance == nullptr) return;

	GameInstance->StartSession();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	bUseSeamlessTravel = true;

	World->ServerTravel("/Game/Maps/Blockout_P?listen");
}