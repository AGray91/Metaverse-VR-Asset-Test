// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Controller/MVR_Player_Controller.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MVR_Boat.h"
#include "../Game_Mode/MVR_Game_Mode.h"
#include "../Game_State/MVR_Game_State.h"


void AMVR_Player_Controller::BeginPlay()
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	Subsystem->AddMappingContext(IMC_Boat_Controls, 0);

	// UI_Main_Menu = CreateWidget<UMVR_UI_Main_Menu>(GetWorld()->GetFirstPlayerController(), UI_Main_Menu_Class);
	UI_Main_Menu = CreateWidget<UMVR_UI_Main_Menu>(this, UI_Main_Menu_Class);
	if (!UI_Main_Menu)
		return;
	UI_Main_Menu->AddToViewport(0);

	UI_Main_Menu->Btn_Exit_Clicked.AddUniqueDynamic(this, &AMVR_Player_Controller::On_Exit_Button_Clicked);
	UI_Main_Menu->Btn_Play_Clicked.AddUniqueDynamic(this, &AMVR_Player_Controller::On_Start_Button_Clicked);

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	DisableInput(this);

	// Setup Main UI...
	// UI_Main = CreateWidget<UMVR_UI_Main>(GetWorld()->GetFirstPlayerController(), UI_Main_Class);
	UI_Main = CreateWidget<UMVR_UI_Main>(this, UI_Main_Class);
	if (!UI_Main)
		return;
}


void AMVR_Player_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* Enhanced_Input = Cast<UEnhancedInputComponent>(InputComponent);
	if (!Enhanced_Input)
		return;

	Enhanced_Input->BindAction(Move_Action, ETriggerEvent::Triggered, this, &AMVR_Player_Controller::Move);
	Enhanced_Input->BindAction(Move_Action, ETriggerEvent::Completed, this, &AMVR_Player_Controller::Move);

	Enhanced_Input->BindAction(Steer_Action, ETriggerEvent::Triggered, this, &AMVR_Player_Controller::Steer);
	Enhanced_Input->BindAction(Steer_Action, ETriggerEvent::Completed, this, &AMVR_Player_Controller::Steer);

	Enhanced_Input->BindAction(Look_Action, ETriggerEvent::Triggered, this, &AMVR_Player_Controller::Look);
	Enhanced_Input->BindAction(Look_Adjust, ETriggerEvent::Triggered, this, &AMVR_Player_Controller::Adjust_Look);
}


void AMVR_Player_Controller::Move(const FInputActionValue& value)
{
	AMVR_Boat* boat = Cast<AMVR_Boat>(GetPawn());
	if (boat)
		boat->Move(value.Get<float>());
}


void AMVR_Player_Controller::Steer(const FInputActionValue& value)
{
	AMVR_Boat* boat = Cast<AMVR_Boat>(GetPawn());
	if (boat)
		boat->Steer(value.Get<float>());
}


void AMVR_Player_Controller::Look(const FInputActionValue& value)
{
	AMVR_Boat* boat = Cast<AMVR_Boat>(GetPawn());
	if (boat)
		boat->Look(value.Get<FVector>());
}


void AMVR_Player_Controller::Adjust_Look(const FInputActionValue& value)
{
	AMVR_Boat* boat = Cast<AMVR_Boat>(GetPawn());
	if (boat)
		boat->Adjust_Look(value.Get<float>());
}


void AMVR_Player_Controller::On_Exit_Button_Clicked()
{
	EndPlay(EEndPlayReason::Quit);
}



void AMVR_Player_Controller::On_Start_Button_Clicked()
{
	Server_Request_Game_Start();
}



void AMVR_Player_Controller::Update_UI_Timer(float value)
{
	if (UI_Main->IsInViewport())
		UI_Main->Set_Timer_Text(get_formatted_time(value));
}



// Called by GameMode. Starts game for this user, updates HUD and gives controls...
void AMVR_Player_Controller::Start_Game()
{
	bShowMouseCursor = false;
	bEnableClickEvents = false;
	EnableInput(this);

	if (!UI_Main_Menu)
		return;

	UI_Main_Menu->SetVisibility(ESlateVisibility::Collapsed);
	UI_Main->AddToViewport(1);
}


// Request GameMode to start game...
void AMVR_Player_Controller::Server_Request_Game_Start_Implementation()
{
	AMVR_Game_Mode* game_mode = GetWorld()->GetAuthGameMode<AMVR_Game_Mode>();
	if (game_mode)
		game_mode->Start_Game();
}


FString AMVR_Player_Controller::get_formatted_time(float value)
{
	FString retVal;

	int32 total_time = FMath::FloorToInt(value * 1000.0f);
	int32 minutes = total_time / 60000;
	int32 seconds = (total_time / 1000) % 60;
	int32 milliseconds = total_time % 1000;

	retVal = FString::Printf(TEXT("%02d:%02d:%03d"), minutes, seconds, milliseconds);

	return retVal;
}