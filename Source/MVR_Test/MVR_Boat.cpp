// Fill out your copyright notice in the Description page of Project Settings.


#include "MVR_Boat.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"



// Sets default values
AMVR_Boat::AMVR_Boat()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	bUseControllerRotationYaw = false;

	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	RootComponent = Origin;

	Boat_Meshes = CreateDefaultSubobject<USceneComponent>("Boat_Meshes");
	Boat_Meshes->SetupAttachment(Origin);

	Spring_Arm = CreateDefaultSubobject<USpringArmComponent>("Spring_Arm");
	Spring_Arm->bUsePawnControlRotation = true;
	Spring_Arm->SetupAttachment(Origin);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(Spring_Arm);

	// Property Defaults...
	Top_Speed = 5000.f;
	Max_Turn_Speed = 100.f;
	Turn_Acceleration = 4.f;
	Look_Speed = 2.f;
	Adjust_Look_Speed = 50.f;
	Acceleration_Speed = 2000.f;
	Deceleration_Speed = 1500.f;
	Friction = 1000.f;

	// Private Defaults...
	move_speed = 0.f;
	turn_speed = 0.f;
}



// Called when the game starts or when spawned
void AMVR_Boat::BeginPlay()
{
	Super::BeginPlay();

	// ********************************************
	// Setup Input Mapping Context...
	// ********************************************
	APlayerController* pc = Cast<APlayerController>(GetController());

	if (pc)
	{
		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());

		if (subsystem)
		{
			subsystem->AddMappingContext(Default_Mapping_Context, 0);
		}
	}
}



// Called every frame
void AMVR_Boat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ********************************************
	// Accelerating/Reversing/Decelerating Logic...
	// ********************************************
	if (FMath::Abs(forward_scalar) > KINDA_SMALL_NUMBER)
	{
		// Move boat back and forwards...
		float target_speed = forward_scalar * Top_Speed;
		move_speed = FMath::FInterpTo(move_speed, target_speed, DeltaTime, Acceleration_Speed / Top_Speed);
	}
	else
	{
		// Slow boat down...
		move_speed = FMath::FInterpTo(move_speed, 0.f, DeltaTime, Deceleration_Speed / Top_Speed);
	}

	// Move Boat...
	FVector MoveDelta = GetActorForwardVector() * move_speed * DeltaTime;
	AddActorWorldOffset(MoveDelta, true);



	// ********************************************
	// Steering Logic...
	// ********************************************
	float speed_factor = FMath::Clamp(move_speed / Top_Speed, 0.f, 1.f);
	float target_yaw_speed = steering_scalar * Max_Turn_Speed * speed_factor;

	turn_speed = FMath::FInterpTo(turn_speed, target_yaw_speed, DeltaTime, Turn_Acceleration);

	FRotator new_rotation = GetActorRotation();
	new_rotation.Yaw += turn_speed * DeltaTime;
	SetActorRotation(new_rotation);
}



// Called to bind functionality to input
void AMVR_Boat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* enhanced_input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Bind Move_Action to input...
		enhanced_input->BindAction(Move_Action, ETriggerEvent::Triggered, this, &AMVR_Boat::Move);
		enhanced_input->BindAction(Move_Action, ETriggerEvent::Completed, this, &AMVR_Boat::Move);

		// Bind Steer_Action to input...
		enhanced_input->BindAction(Steer_Action, ETriggerEvent::Triggered, this, &AMVR_Boat::Steer);
		enhanced_input->BindAction(Steer_Action, ETriggerEvent::Completed, this, &AMVR_Boat::Steer);

		enhanced_input->BindAction(Look_Action, ETriggerEvent::Triggered, this, &AMVR_Boat::Look);
		enhanced_input->BindAction(Look_Adjust, ETriggerEvent::Triggered, this, &AMVR_Boat::Adjust_Look);
	}
}



void AMVR_Boat::Move(const FInputActionValue& value)
{
	forward_scalar = value.Get<float>();
}

void AMVR_Boat::Steer(const FInputActionValue& value)
{
	steering_scalar = value.Get<float>();
}

void AMVR_Boat::Look(const FInputActionValue& value)
{
	FVector look_vector = value.Get<FVector>();

	AddControllerYawInput(look_vector.X * Look_Speed);
	AddControllerPitchInput(look_vector.Y * Look_Speed);
}

void AMVR_Boat::Adjust_Look(const FInputActionValue& value)
{
	float length_delta = value.Get<float>();
	Spring_Arm->TargetArmLength += length_delta * Adjust_Look_Speed;
}