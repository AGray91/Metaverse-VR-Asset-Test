// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MVR_Game_State.generated.h"

/**
 * 
 */
UCLASS()
class MVR_TEST_API AMVR_Game_State : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AMVR_Game_State();


protected:
	virtual void Tick(float DeltaTime) override;


public:

	UPROPERTY(ReplicatedUsing=OnRep_Game_Started)
	bool bGame_Started;
	
	UFUNCTION()
	void OnRep_Game_Started();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Category = "MVR")
	float Get_Elapsed_Time();


private:
	float elapsed_time;
};
