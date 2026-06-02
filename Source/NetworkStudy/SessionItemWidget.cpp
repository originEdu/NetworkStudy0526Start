// Fill out your copyright notice in the Description page of Project Settings.


#include "SessionItemWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void USessionItemWidget::SetInfo(FBlueprintSessionResult InSessionResult)
{
	Result = InSessionResult;
	RefreshUI();
}

void USessionItemWidget::RefreshUI()
{
	//방이름
	FString SessionName;
	Result.OnlineResult.Session.SessionSettings.Get("SESSION_NAME", SessionName); //SESSION_NAME키로 세션이름 정보 가지고 오기
	//Result.OnlineResult.Session.SessionSettings.Set("SESSION_NAME", SessionName, EOnlineDataAdvertisementType::ViaOnlineService);
	Txt_SessionName->SetText(FText::FromString(SessionName));

	//현재 인원수(2) = 최대 인원수(10) - 접속 가능한 인원수(8)
	const int32 MaxPlayers = Result.OnlineResult.Session.SessionSettings.NumPublicConnections;
	const int32 CurrentPlayers = MaxPlayers - Result.OnlineResult.Session.NumOpenPublicConnections;
	FString PlayerCountString = FString::Printf(TEXT("(%d / %d)"), CurrentPlayers, MaxPlayers);
	Txt_PlayerCount->SetText(FText::FromString(PlayerCountString)); //ex) (2/10)

	//맵이름
	FString MapName;
	Result.OnlineResult.Session.SessionSettings.Get("MAP_NAME", MapName); //MAP_NAME키로 맵이름 가지고 오기
	Txt_MapName->SetText(FText::FromString(MapName));
}