// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "../UI/MVR_UI_Main_Menu.h"
#include "../UI/MVR_UI_Main.h"
#include "MVR_Player_Controller.generated.h"

/**
 * 
 */
UCLASS()
class MVR_TEST_API AMVR_Player_Controller : public APlayerController
{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;


public:
	virtual void SetupInputComponent() override;
	

protected:

	// Add Custom Input...
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* IMC_Boat_Controls;


	// Input Components...
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* Move_Action;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* Steer_Action;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* Look_Action;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* Look_Adjust;


	// UI Elements...
	UPROPERTY(EditAnywhere, Category = "MVR")
	TSubclassOf<UMVR_UI_Main_Menu> UI_Main_Menu_Class;

	UPROPERTY(EditAnywhere, Category = "MVR")
	TSubclassOf<UMVR_UI_Main> UI_Main_Class;


protected:

	// Input Handlers...
	UFUNCTION()
	void Move(const FInputActionValue& value);

	UFUNCTION()
	void Steer(const FInputActionValue& value);

	UFUNCTION()
	void Look(const FInputActionValue& value);

	UFUNCTION()
	void Adjust_Look(const FInputActionValue& value);


	// Handles when the Start Game Button Is clicked...
	UFUNCTION(BlueprintCallable, Category = "MVR")
	void On_Start_Button_Clicked();

	// Handles when the Exit button is clicked...
	UFUNCTION(BlueprintCallable, Category = "MVR")
	void On_Exit_Button_Clicked();

	// Request GameMode starts game...
	UFUNCTION(Server, Reliable)
	void Server_Request_Game_Start();


public:
	UFUNCTION(BlueprintCallable, Category = "MVR")
	void Update_UI_Timer(float value);


public:
	// Called by GameMode. Starts game for this user, updates HUD and gives controls...
	UFUNCTION(BlueprintCallable, Category = "MVR")
	void Start_Game();


private:
	UMVR_UI_Main_Menu* UI_Main_Menu;
	UMVR_UI_Main* UI_Main;

	FString get_formatted_time(float);
};
