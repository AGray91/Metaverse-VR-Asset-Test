// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MVR_UI_End_Menu.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEndMenuBtnClicked);

/**
 * 
 */
UCLASS()
class MVR_TEST_API UMVR_UI_End_Menu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;
	virtual void NativeDestruct() override;


public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* _Txt_Result;

	UPROPERTY(meta = (BindWidget))
	class UButton* _Btn_Restart;

	UPROPERTY(meta = (BindWidget))
	class UButton* _Btn_Exit;


	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "MVR")
	FEndMenuBtnClicked Btn_Restart_Clicked;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "MVR")
	FEndMenuBtnClicked Btn_Exit_Clicked;


	UFUNCTION(BlueprintCallable, Category = "MVR")
	void Set_Result_Text(FString text);


protected:
	UFUNCTION(BlueprintCallable, Category = "MVR")
	void On_Btn_Restart_Clicked();

	UFUNCTION(BlueprintCallable, Category = "MVR")
	void On_Btn_Exit_Clicked();
};
