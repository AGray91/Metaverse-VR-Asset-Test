// Fill out your copyright notice in the Description page of Project Settings.


#include "BoatMovementComponent.h"

// Sets default values for this component's properties
UBoatMovementComponent::UBoatMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Property Defaults...
	Top_Speed = 5000.f;
	Max_Turn_Speed = 100.f;
	Turn_Acceleration = 4.f;
	Acceleration_Speed = 2000.f;
	Friction = 1500.f;
	Lift = 5.f;
}


// Called when the game starts
void UBoatMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	parent_actor = GetOwner();
}


// Called every frame
void UBoatMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);



	// Accelerating/Reversing/Decelerating Logic...
	if (FMath::Abs(forward_scalar) > KINDA_SMALL_NUMBER)
	{
		// Move boat back and forwards...
		float target_speed = forward_scalar * Top_Speed;
		move_speed = FMath::FInterpTo(move_speed, target_speed, DeltaTime, Acceleration_Speed / Top_Speed);
	}
	else
	{
		// Slow boat down...
		move_speed = FMath::FInterpTo(move_speed, 0.f, DeltaTime, Friction / Top_Speed);
	}

	// Move Boat...
	FVector move_delta = parent_actor->GetActorForwardVector() * move_speed * DeltaTime;
	parent_actor->AddActorWorldOffset(move_delta, true);



	// Lift Logic...
	if (Boat_Meshes != nullptr)
	{
		float lift_factor = FMath::GetMappedRangeValueClamped(FVector2D(0.0f, Top_Speed), FVector2D(0.0f, Lift), move_speed);
		FRotator lift_rotation = Boat_Meshes->GetRelativeRotation();
		lift_rotation.Pitch = FMath::FInterpTo(lift_rotation.Pitch, lift_factor, DeltaTime, 2.5f);
		Boat_Meshes->SetRelativeRotation(lift_rotation);
	}



	// Steering Logic...
	float speed_factor = FMath::Clamp(move_speed / Top_Speed, -1.f, 1.f);
	float target_yaw_speed = steering_scalar * Max_Turn_Speed * speed_factor;

	turn_speed = FMath::FInterpTo(turn_speed, target_yaw_speed, DeltaTime, Turn_Acceleration);

	FRotator new_rotation = parent_actor->GetActorRotation();
	new_rotation.Yaw += turn_speed * DeltaTime;
	parent_actor->SetActorRotation(new_rotation);
}


void UBoatMovementComponent::Accelerate(float scalar)
{
	forward_scalar = scalar;
}


void UBoatMovementComponent::Steer(float scalar)
{
	steering_scalar = scalar;
}

