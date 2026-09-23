// Fill out your copyright notice in the Description page of Project Settings.


#include "Game_State/MVR_Game_State.h"
#include "Net/UnrealNetwork.h"
#include "../Player_Controller/MVR_Player_Controller.h"


AMVR_Game_State::AMVR_Game_State()
{
	PrimaryActorTick.bCanEverTick = true;
	bGame_Started = false;

	elapsed_time = 0.0f;
}


void AMVR_Game_State::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!bGame_Started)
		return;

	elapsed_time += DeltaSeconds;

	for (FConstPlayerControllerIterator itr = GetWorld()->GetPlayerControllerIterator(); itr; ++itr)
	{
		AMVR_Player_Controller* controller = Cast<AMVR_Player_Controller>(itr->Get());
		if (controller)
			controller->Update_UI_Timer(elapsed_time);
	}
}


void AMVR_Game_State::OnRep_Game_Started()
{

}


void AMVR_Game_State::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMVR_Game_State, bGame_Started);
}


float AMVR_Game_State::Get_Elapsed_Time()
{
	return elapsed_time;
}
