// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "LobbyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSTUDY_API ALobbyPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool Ready;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_Nickname)
	FText Nickname;

	UFUNCTION(BlueprintImplementableEvent)
	void RefreshLobbyUI();

	UFUNCTION()
	void OnRep_Nickname(); //닉네임이 변경되었을 때 호출

	UFUNCTION(BlueprintCallable)
	void SetNickname(const FText& NewNickname);

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty> &OutLifetimeProps) const;

	
	
	
};
