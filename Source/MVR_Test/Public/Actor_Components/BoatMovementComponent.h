// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BoatMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MVR_TEST_API UBoatMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBoatMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



	// Variables...
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Top_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Acceleration_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Max_Turn_Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Turn_Acceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Friction;

	// The angle at which the Boat lifts due to wind resistance...
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	float Lift;

	// For specific effects like lift, plugin in a Scene Component that parents the boat meshes...
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MVR_Boat | Properties")
	USceneComponent* Boat_Meshes;



	// Functions...
	// Accelerate the boat forwards (1.0) or backwards (-1.0) depending on scalar value... 
	UFUNCTION(BlueprintCallable, Category = "MVR_Boat")
	void Accelerate(float scalar);

	// Turn the boat left (-1.0) or right (1.0) depending on scalar value...
	UFUNCTION(BlueprintCallable, Category = "MVR_Boat")
	void Steer(float scalar);



private:
	AActor* parent_actor;

	// Is the boat moving forwards or backwards...
	float forward_scalar;

	// Is the boat moving left or right...
	float steering_scalar;

	// How fast is the boat currently moving...
	float move_speed;

	// How much is the boating currently turning...
	float turn_speed;
};
