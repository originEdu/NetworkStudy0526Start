// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/UI/LobbyUserWidget.h"
#include "Lobby/Contents/LobbyPlayerState.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SessionListWidget.h"

void ULobbyUserWidget::SetInfo(ALobbyPlayerState* InPlayerState)
{
	PlayerState = InPlayerState;
	RefreshUI();
}

void ULobbyUserWidget::RefreshUI()
{
	if (PlayerState == nullptr)
	{
		return;
	}

	//지역변수 초기화(캐싱)
	bool isLocalController = false;
	APlayerController* PlayerController = PlayerState->GetPlayerController();
	if (PlayerController)
	{
		isLocalController = PlayerController->IsLocalController();
	}
	bool isReady = PlayerState->Ready;
	bool isServer = UKismetSystemLibrary::IsServer(GetWorld());

	//UI 숨겨두기
	Txt_Ready->SetVisibility(ESlateVisibility::Hidden);
	Editable_PlayerName->SetVisibility(ESlateVisibility::Hidden);
	Btn_Ready->SetVisibility(ESlateVisibility::Hidden);
	Btn_KickPlayer->SetVisibility(ESlateVisibility::Hidden);

	//레디 텍스트 노출
	if (isReady)
	{
		Txt_Ready->SetVisibility(ESlateVisibility::Visible);
	}

	//레디 버튼 노출
	if (isLocalController && !isReady)
	{
		Btn_Ready->SetVisibility(ESlateVisibility::Visible);
	}

	//서버 제외 강퇴버튼 노출
	if (isServer && !isLocalController)
	{
		Btn_KickPlayer->SetVisibility(ESlateVisibility::Visible);
	}

	//닉네임이름 설정
	Editable_PlayerName->SetText(PlayerState->Nickname);
	Editable_PlayerName->SetVisibility(ESlateVisibility::Visible);
	if (isReady)
	{
		Editable_PlayerName->SetIsReadOnly(true);
	}
	else
	{
		Editable_PlayerName->SetIsReadOnly(!isLocalController);
	}
}
