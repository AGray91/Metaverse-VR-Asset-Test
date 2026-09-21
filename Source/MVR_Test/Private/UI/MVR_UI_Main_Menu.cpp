// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MVR_UI_Main_Menu.h"
#include "Components/Button.h"


void UMVR_UI_Main_Menu::NativePreConstruct()
{
}


void UMVR_UI_Main_Menu::NativeConstruct()
{
	_Btn_Exit->OnClicked.AddUniqueDynamic(this, &UMVR_UI_Main_Menu::Btn_Exit_OnClicked);
	_Btn_Play->OnClicked.AddUniqueDynamic(this, &UMVR_UI_Main_Menu::Btn_Play_OnClicked);
}


void UMVR_UI_Main_Menu::NativeDestruct()
{
}


void UMVR_UI_Main_Menu::Btn_Exit_OnClicked()
{
	Btn_Exit_Clicked.Broadcast();
}


void UMVR_UI_Main_Menu::Btn_Play_OnClicked()
{
	Btn_Play_Clicked.Broadcast();
}
