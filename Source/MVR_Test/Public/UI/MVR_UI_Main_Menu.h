// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MVR_UI_Main_Menu.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonClicked);

UCLASS()
class MVR_TEST_API UMVR_UI_Main_Menu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;
	virtual void NativeDestruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* _Canvas;

	UPROPERTY(meta = (BindWidget))
	class UButton* _Btn_Play;

	UPROPERTY(meta = (BindWidget))
	class UButton* _Btn_Join;

	UPROPERTY(meta = (BindWidget))
	class UButton* _Btn_Exit;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "MVR")
	FButtonClicked Btn_Exit_Clicked;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "MVR")
	FButtonClicked Btn_Play_Clicked;

protected:

	UFUNCTION()
	void Btn_Exit_OnClicked();

	UFUNCTION()
	void Btn_Play_OnClicked();
};
