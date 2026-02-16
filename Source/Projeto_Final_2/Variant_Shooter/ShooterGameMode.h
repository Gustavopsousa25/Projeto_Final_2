// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterUI.h"
#include "GameOverWidget.h"
#include "ShooterGameMode.generated.h"

class UShooterUI;

/**
 *  Simple GameMode for a first person shooter game
 *  Manages game UI
 *  Keeps track of team scores
 */
UCLASS(abstract)
class PROJETO_FINAL_2_API AShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

	/** Type of UI widget to spawn */
	UPROPERTY(EditAnywhere, Category="Shooter")
	TSubclassOf<UShooterUI> ShooterUIClass;

	/** Pointer to the UI widget */
	TObjectPtr<UShooterUI> ShooterUI;

	/** Map of scores by team ID */
	TMap<uint8, int32> TeamScores;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Shooter")
	int32 currentScore;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Shooter")
	int32 timer;

protected:

	/** Gameplay initialization */
	virtual void BeginPlay() override;

public:

	/** Increases the score for the given team */
	void IncrementTeamScore(uint8 TeamByte);
	void UpdateTimer(float NewTimer);
	UFUNCTION(BlueprintCallable, Category = "ShooterGameMode")
	void IncrementScore(int32 newScore);
	UFUNCTION(BlueprintCallable, Category = "ShooterGameMode")
	void IncrementTimer(float value);
	UFUNCTION(BlueprintCallable, Category = "ShooterGameMode")
	void OnTimerEnded();
	UPROPERTY(EditAnywhere, Category = "Shooter")
	TSubclassOf<UGameOverWidget> GameOverWidgetClass;

	UPROPERTY()
	UGameOverWidget* GameOverWidget;
private:
	UFUNCTION(BlueprintCallable, Category = "Timer")
	void StartTimer();
};
