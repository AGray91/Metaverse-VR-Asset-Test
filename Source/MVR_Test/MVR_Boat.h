// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "MVR_Boat.generated.h"

UCLASS()
class MVR_TEST_API AMVR_Boat : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMVR_Boat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	// Input Components...

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* Move_Action;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* Steer_Action;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* Look_Action;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* Look_Adjust;


	// Add Custom Input...
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* Default_Mapping_Context;


	// Actor Components...
	UPROPERTY(BlueprintReadOnly, Category = "MVR_Boat | Components")
	USceneComponent* Origin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Components")
	USceneComponent* Boat_Meshes;

	UPROPERTY(EditAnywhere, Category = "MVR_Boat | Components")
	USpringArmComponent* Spring_Arm;

	UPROPERTY(EditAnywhere, Category = "MVR_Boat | Components")
	UCameraComponent* Camera;


	// Variables...
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Top_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Acceleration_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Deceleration_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Max_Turn_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Turn_Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Look_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Adjust_Look_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Friction;

protected:

	// FUNCTIONS...
	void Move(const FInputActionValue& value);
	void Steer(const FInputActionValue& value);
	void Look(const FInputActionValue& value);
	void Adjust_Look(const FInputActionValue& value);

private:
	float forward_scalar;
	float steering_scalar;
	float move_speed;
	float turn_speed;
};
