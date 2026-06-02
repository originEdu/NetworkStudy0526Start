// Fill out your copyright notice in the Description page of Project Settings.

#include "Lobby/Contents/LobbyPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Lobby/UI/LobbyUserWidget.h"

void ALobbyPlayerState::OnRep_Nickname()
{
	RefreshLobbyUI();
}

void ALobbyPlayerState::SetNickname(const FText& NewNickname)
{
	if (!HasAuthority()) return;
	Nickname = NewNickname;
	OnRep_Nickname();
}

void ALobbyPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyPlayerState, Nickname);
}
