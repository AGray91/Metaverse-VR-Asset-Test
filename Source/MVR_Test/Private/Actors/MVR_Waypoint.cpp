// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/MVR_Waypoint.h"
#include "../Player_Controller/MVR_Player_Controller.h"
#include "../Pawns/MVR_Boat.h"


// Sets default values
AMVR_Waypoint::AMVR_Waypoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Waypoint_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Waypoint_Collision"));
	Waypoint_Collision->SetCollisionProfileName(FName("OverlapAllDynamic"), true);
	RootComponent = Waypoint_Collision;

	overlapped = false;

}


// Called when the game starts or when spawned
void AMVR_Waypoint::BeginPlay()
{
	Super::BeginPlay();
	
	Waypoint_Collision->OnComponentBeginOverlap.AddUniqueDynamic(this, &AMVR_Waypoint::On_Boat_Overlap_Begin);
	Waypoint_Collision->OnComponentEndOverlap.AddUniqueDynamic(this, &AMVR_Waypoint::On_Boat_Overlap_End);
}


// Called every frame
void AMVR_Waypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMVR_Waypoint::On_Boat_Overlap_Begin(UPrimitiveComponent* overlapped_comp, AActor* other_actor, UPrimitiveComponent* other_comp, int32 other_body_index, bool from_sweep, const FHitResult& sweep_result)
{
	if (overlapped)
		return;

	AMVR_Boat* pawn = Cast<AMVR_Boat>(other_actor);
	if (!pawn)
		return;

	if (AMVR_Player_Controller* controller = pawn->GetController<AMVR_Player_Controller>())
	{
		overlapped = true;
		controller->Start_End_Timer();
	}
}


void AMVR_Waypoint::On_Boat_Overlap_End(UPrimitiveComponent* overlapped_comp, AActor* other_actor, UPrimitiveComponent* other_comp, int32 other_body_index)
{
	AMVR_Boat* pawn = Cast<AMVR_Boat>(other_actor);
	if (!pawn)
		return;

	if (AMVR_Player_Controller* controller = pawn->GetController<AMVR_Player_Controller>())
	{
		overlapped = false;
		controller->Restart_End_Timer();
	}
}

