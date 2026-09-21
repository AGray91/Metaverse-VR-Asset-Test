// Fill out your copyright notice in the Description page of Project Settings.


#include "Game_Mode/MVR_Game_Mode.h"
#include "GameFramework/Pawn.h"
#include "Kismet/KismetSystemLibrary.h"

AMVR_Game_Mode::AMVR_Game_Mode()
{
	bgame_playing = true;
}


void AMVR_Game_Mode::BeginPlay()
{
	UI_Main_Menu = CreateWidget<UMVR_UI_Main_Menu>(GetWorld()->GetFirstPlayerController(), UI_Main_Menu_Class);
	if (!UI_Main_Menu)
		return;
	UI_Main_Menu->AddToViewport(0);

	UI_Main_Menu->Btn_Exit_Clicked.AddUniqueDynamic(this, &AMVR_Game_Mode::Exit_Game);
	UI_Main_Menu->Btn_Play_Clicked.AddUniqueDynamic(this, &AMVR_Game_Mode::Play_Game);

	Set_Is_Game_Playing(false);
}


void AMVR_Game_Mode::Exit_Game()
{
	APlayerController* pc = Cast<APlayerController>(GetWorld()->GetFirstLocalPlayerFromController());
	UKismetSystemLibrary::QuitGame(GetWorld(), pc, EQuitPreference::Quit, false);
}


void AMVR_Game_Mode::Play_Game()
{
	if (!UI_Main_Menu)
		return;

	UI_Main_Menu->SetVisibility(ESlateVisibility::Collapsed);

	Set_Is_Game_Playing(true);
}


void AMVR_Game_Mode::Set_Is_Game_Playing(bool val)
{
	if (val)
	{
		APlayerController* pc = GetWorld()->GetFirstPlayerController();
		if (pc)
		{
			pc->bShowMouseCursor = false;
			pc->bEnableClickEvents = false;
			pc->EnableInput(pc);
		}
	}
	else
	{
		APlayerController* pc = GetWorld()->GetFirstPlayerController();
		if (pc)
		{
			pc->bShowMouseCursor = true;
			pc->bEnableClickEvents = true;
			pc->DisableInput(pc);
		}
	}

	bgame_playing = val;
	
}


bool AMVR_Game_Mode::Get_Is_Game_Playing()
{
	return bgame_playing;
}
