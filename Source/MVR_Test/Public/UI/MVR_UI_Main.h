// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MVR_UI_Main.generated.h"

/**
 * 
 */
UCLASS()
class MVR_TEST_API UMVR_UI_Main : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;
	virtual void NativeDestruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* _Canvas;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* _Txt_Timer;

public:
	UFUNCTION(BlueprintCallable, Category = "MVR")
	void Set_Timer_Text(FString txt);
};
