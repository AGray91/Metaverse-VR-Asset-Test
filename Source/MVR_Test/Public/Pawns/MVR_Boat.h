// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "../Actor_Components/BoatMovementComponent.h"
#include "Components/BoxComponent.h"
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

protected:

	// Actor Components...
	UPROPERTY(BlueprintReadOnly, Category = "MVR_Boat | Components")
	USceneComponent* Origin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Components")
	USceneComponent* Boat_Meshes;

	UPROPERTY(EditAnywhere, Category = "MVR_Boat | Components")
	USpringArmComponent* Spring_Arm;

	UPROPERTY(EditAnywhere, Category = "MVR_Boat | Components")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "MVR_Boat | Components")
	UBoatMovementComponent* Boat_Movement;

	UPROPERTY(EditAnywhere, Category = "MVR_Boat | Components")
	UBoxComponent* Boat_Collision;




	// Properties...
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Look_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Adjust_Look_Speed;

public:

	// FUNCTIONS...
	UFUNCTION(BlueprintCallable, Category = "MVR_Boat | Functions")
	void Move(const float value);

	UFUNCTION(BlueprintCallable, Category = "MVR_Boat | Functions")
	void Steer(const float value);

	UFUNCTION(BlueprintCallable, Category = "MVR_Boat | Functions")
	void Look(const FVector value);

	UFUNCTION(BlueprintCallable, Category = "MVR_Boat | Functions")
	void Adjust_Look(const float value);
};
