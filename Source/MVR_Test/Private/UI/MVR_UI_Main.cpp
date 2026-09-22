// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MVR_UI_Main.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"


void UMVR_UI_Main::NativeConstruct()
{
}


void UMVR_UI_Main::NativePreConstruct()
{
}


void UMVR_UI_Main::NativeDestruct()
{
}


void UMVR_UI_Main::Set_Timer_Text(FString txt)
{
	if (_Txt_Timer)
		_Txt_Timer->SetText(FText::FromString(txt));
}
