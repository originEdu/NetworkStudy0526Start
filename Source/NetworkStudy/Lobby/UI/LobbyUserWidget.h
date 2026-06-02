// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyUserWidget.generated.h"

class UTextBlock;
class UEditableTextBox;
class ALobbyPlayerState;
class UButton;
/**
 * 
 */
UCLASS()
class NETWORKSTUDY_API ULobbyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable) //블루프린트에서도 호출이 가능하다
	void SetInfo(ALobbyPlayerState* InPlayerState);

	UFUNCTION(BlueprintCallable) 
	void RefreshUI();

protected:
	UPROPERTY(BlueprintReadOnly,meta=(BindWidget))
	TObjectPtr<UTextBlock> Txt_Ready; //멤버변수한해서 TObjectPtr사용
										//레디 텍스트 
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UEditableTextBox> Editable_PlayerName; //닉네임 기입하는 박스

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> Btn_Ready; //레드 버튼

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> Btn_KickPlayer; //강퇴 버튼

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<ALobbyPlayerState> PlayerState; //플레이어스테이트

};
