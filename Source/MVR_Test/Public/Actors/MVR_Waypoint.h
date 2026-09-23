// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MVR_Waypoint.generated.h"

UCLASS()
class MVR_TEST_API AMVR_Waypoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMVR_Waypoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(BlueprintReadWrite, Category = "MVR")
	UBoxComponent* Waypoint_Collision;

	UFUNCTION(BlueprintCallable, Category = "MVR")
	void On_Boat_Overlap_Begin(UPrimitiveComponent* overlapped_comp, AActor* other_actor, UPrimitiveComponent* other_comp, int32 other_body_index, bool from_sweep, const FHitResult& sweep_result);

	UFUNCTION(BlueprintCallable, Category = "MVR")
	void On_Boat_Overlap_End(UPrimitiveComponent* overlapped_comp, AActor* other_actor, UPrimitiveComponent* other_comp, int32 other_body_index);

private:
	bool overlapped;
};
