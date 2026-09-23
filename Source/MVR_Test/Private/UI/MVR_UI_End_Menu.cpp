// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MVR_UI_End_Menu.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


void UMVR_UI_End_Menu::NativeConstruct()
{
	_Btn_Restart->OnClicked.AddUniqueDynamic(this, &UMVR_UI_End_Menu::On_Btn_Restart_Clicked);
	_Btn_Exit->OnClicked.AddUniqueDynamic(this, &UMVR_UI_End_Menu::On_Btn_Exit_Clicked);
}


void UMVR_UI_End_Menu::NativePreConstruct()
{
}


void UMVR_UI_End_Menu::NativeDestruct()
{
}


void UMVR_UI_End_Menu::On_Btn_Restart_Clicked()
{
	Btn_Restart_Clicked.Broadcast();
}


void UMVR_UI_End_Menu::On_Btn_Exit_Clicked()
{
	Btn_Exit_Clicked.Broadcast();
}


void UMVR_UI_End_Menu::Set_Result_Text(FString text)
{
	_Txt_Result->SetText(FText::FromString(text));
}
