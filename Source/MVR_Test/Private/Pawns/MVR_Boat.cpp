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

	Boat_Movement = CreateDefaultSubobject<UBoatMovementComponent>("Boat_Movement");
	Boat_Movement->Boat_Meshes = Boat_Meshes;

	// Look properties...
	Look_Speed = 2.f;
	Adjust_Look_Speed = 50.f;
}


// Called when the game starts or when spawned
void AMVR_Boat::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void AMVR_Boat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMVR_Boat::Move(const float value)
{
	Boat_Movement->Accelerate(value);
}


void AMVR_Boat::Steer(const float value)
{
	Boat_Movement->Steer(value);
}


void AMVR_Boat::Look(const FVector value)
{
	AddControllerYawInput(value.X * Look_Speed);
	AddControllerPitchInput(value.Y * Look_Speed);
}


void AMVR_Boat::Adjust_Look(const float value)
{
	Spring_Arm->TargetArmLength += value * Adjust_Look_Speed;
}