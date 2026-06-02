// Fill out your copyright notice in the Description page of Project Settings.


#include "SessionListWidget.h"
#include "SessionItemWidget.h"
#include "Components/WrapBox.h"
#include "Components/Button.h"

bool USessionListWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	};

	SetInfo();
	return true;
}

void USessionListWidget::SetInfo()
{
	//child UI 만들어진거 비우기
	Sessions.Empty();

	//child UI 틀만 10개 만들어 두기
	for (int i = 0; i < 10; ++i)
	{
		//생성할 UI 클래스 레퍼런스가 없으면 넘기기
		if (SessionItemClass == nullptr)
		{
			continue;
		}
		//child UI 생성
		USessionItemWidget* ChildWidget = CreateWidget<USessionItemWidget>(GetWorld(), SessionItemClass);

		//제대로 생성되었는지 검증
		if (ChildWidget == nullptr)
		{
			continue;
		}

		//WrapBox(UI)에 차일드로 붙이기
		SessionList->AddChildToWrapBox(ChildWidget);

		//데이터(인스턴스)로써 만들어진 차일드 Sessions에 저장
		Sessions.Add(ChildWidget);
	}

	//UI갱신
	RefreshUI();
}

void USessionListWidget::RefreshUI()
{
	//매번 방의 정보를 확인 -> Session 확인
	//세션(방)이 몇개 있는지 확인
	const int32 SessionLength = SessionInfos.Num();

	for (int32 i = 0; i < Sessions.Num(); ++i)
	{
		const int32 index = i;
		if (index < SessionLength)
		{
			//차일드 UI 보이게
			Sessions[index]->SetVisibility(ESlateVisibility::Visible);
			FBlueprintSessionResult Result = SessionInfos[index];
			//세션정보 넘겨줘서 차일드 위젯에 데이터 채우기
			Sessions[index]->SetInfo(Result);
		}
		else
		{
			//차일드 UI 안보이게
			Sessions[index]->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}