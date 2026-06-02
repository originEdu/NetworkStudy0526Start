// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.generated.h"

class ALobbyPlayerState;
class UButton;
class UVerticalBox;
class ULobbyUserWidget;
/**
 * 
 */
UCLASS()
class NETWORKSTUDY_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable,BlueprintPure)
	TArray<ALobbyPlayerState*> GetBPLobbyPlayerStates();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	ALobbyPlayerState* GetBPLobbyPlayerStateAtIndex(int32 InIndex);
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UVerticalBox> UserList;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> Btn_Close;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> Btn_GameConfig;

protected:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TSubclassOf<ULobbyUserWidget> LobbyUserWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	TArray<TObjectPtr<ULobbyUserWidget>> LobbyUsers;



};
