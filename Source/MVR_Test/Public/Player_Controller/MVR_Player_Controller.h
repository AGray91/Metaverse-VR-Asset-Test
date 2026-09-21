// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
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


protected:
	UFUNCTION()
	void Move(const FInputActionValue& value);

	UFUNCTION()
	void Steer(const FInputActionValue& value);

	UFUNCTION()
	void Look(const FInputActionValue& value);

	UFUNCTION()
	void Adjust_Look(const FInputActionValue& value);
};
