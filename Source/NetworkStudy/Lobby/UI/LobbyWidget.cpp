// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/UI/LobbyWidget.h"
#include "Lobby/Contents/LobbyPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameStateBase.h"

TArray<ALobbyPlayerState*> ULobbyWidget::GetBPLobbyPlayerStates()
{
	TArray<ALobbyPlayerState*> LobbyPlayerStates;
	AGameStateBase* GameState = UGameplayStatics::GetGameState(GetWorld());
	if (GameState)
	{
		for (APlayerState* PlayerState : GameState->PlayerArray)
		{
			ALobbyPlayerState* LobbyPlayerState = Cast<ALobbyPlayerState>(PlayerState);
			if (LobbyPlayerState)
			{
				LobbyPlayerStates.Add(LobbyPlayerState);
			}
		}
	}

	return LobbyPlayerStates;
}

ALobbyPlayerState* ULobbyWidget::GetBPLobbyPlayerStateAtIndex(int32 InIndex)
{
	TArray<ALobbyPlayerState*> LobbyPlayerStates= GetBPLobbyPlayerStates();
	if (LobbyPlayerStates.IsValidIndex(InIndex))
	{
		return LobbyPlayerStates[InIndex];
	}

	return nullptr;
}
