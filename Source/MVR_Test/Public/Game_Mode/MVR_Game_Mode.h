// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "../UI/MVR_UI_Main_Menu.h"
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
	
protected:
	UPROPERTY(EditAnywhere, Category = "MVR")
	TSubclassOf<UMVR_UI_Main_Menu> UI_Main_Menu_Class;

public:
	UFUNCTION(BlueprintCallable, Category = "MVR")
	void Exit_Game();

	UFUNCTION(BlueprintCallable, Category = "MVR")
	void Play_Game();

	UFUNCTION(BlueprintCallable, Category = "MVR")
	void Set_Is_Game_Playing(bool val);

	UFUNCTION(BlueprintCallable, Category = "MVR")
	bool Get_Is_Game_Playing();

private:
	bool bgame_playing;
	UMVR_UI_Main_Menu* UI_Main_Menu;
};
