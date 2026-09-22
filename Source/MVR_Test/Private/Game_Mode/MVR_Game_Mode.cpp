// Fill out your copyright notice in the Description page of Project Settings.


#include "Game_Mode/MVR_Game_Mode.h"
#include "GameFramework/Pawn.h"
#include "Kismet/KismetSystemLibrary.h"
#include "../Player_Controller/MVR_Player_Controller.h"
#include "../Game_State/MVR_Game_State.h"

AMVR_Game_Mode::AMVR_Game_Mode()
{

}


void AMVR_Game_Mode::BeginPlay()
{

}

void AMVR_Game_Mode::Start_Game()
{
	AMVR_Game_State* game_state = GetGameState<AMVR_Game_State>();
	if (!game_state)
		return;

	game_state->bGame_Started = true;
	MulticastOnGameStarted();
}

void AMVR_Game_Mode::MulticastOnGameStarted_Implementation()
{
	for (FConstPlayerControllerIterator itr = GetWorld()->GetPlayerControllerIterator(); itr; ++itr)
	{
		AMVR_Player_Controller* controller = Cast<AMVR_Player_Controller>(itr->Get());
		if (controller)
			controller->Start_Game();
	}
}
