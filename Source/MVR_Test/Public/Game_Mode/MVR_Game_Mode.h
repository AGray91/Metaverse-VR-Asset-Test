// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "../UI/MVR_UI_Main_Menu.h"
#include "../UI/MVR_UI_Main.h"
#include "MVR_Game_Mode.generated.h"

/**
 * 
 */
UCLASS()
class MVR_TEST_API AMVR_Game_Mode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMVR_Game_Mode();

protected:
	virtual void BeginPlay() override;

public:

	// Initialises the game...
	UFUNCTION(BlueprintCallable, Category = "MVR")
	void Start_Game();

	UFUNCTION(BlueprintCallable, Category = "MVR")
	void Restart_Game();

	// Tells every user/controller to start their game...
	UFUNCTION(NetMulticast, Reliable)
	void MulticastOnGameStarted();
};
