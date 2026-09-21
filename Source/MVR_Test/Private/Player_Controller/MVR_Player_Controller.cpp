// Fill out your copyright notice in the Description page of Project Settings.


#include "Player_Controller/MVR_Player_Controller.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "MVR_Boat.h"


void AMVR_Player_Controller::BeginPlay()
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	Subsystem->AddMappingContext(IMC_Boat_Controls, 0);
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