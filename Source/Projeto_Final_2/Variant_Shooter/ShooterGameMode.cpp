// Copyright Epic Games, Inc. All Rights Reserved.


#include "Variant_Shooter/ShooterGameMode.h"
#include "ShooterUI.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameOverWidget.h"

void AShooterGameMode::BeginPlay()
{
	Super::BeginPlay();
	// create the UI
	ShooterUI = CreateWidget<UShooterUI>(UGameplayStatics::GetPlayerController(this, 0), ShooterUIClass);
	FTimerHandle myTimer;
	ShooterUI->TimerEnded.AddDynamic(this, &AShooterGameMode::OnTimerEnded);
	GetWorld()->GetTimerManager().SetTimer(myTimer, this, &AShooterGameMode::StartTimer, 1.0f, true);
	ShooterUI->AddToViewport();
	ShooterUI->BP_UpdateScore(0);
}

void AShooterGameMode::IncrementTimer(float NewTimer)
{
	timer = FMath::RoundToInt32(NewTimer + timer);
}
void AShooterGameMode::IncrementScore(int32 newScore)
{
	currentScore = currentScore + newScore;
	currentScore = FMath::Clamp(currentScore, 0, 9999);
	ShooterUI->BP_UpdateScore(currentScore);
}
void AShooterGameMode::StartTimer()
{
	timer--;
	timer = FMath::Clamp(timer, 0,timer);
	ShooterUI->UpdateTimer(timer);
	if(timer <= 0)
	{
		ShooterUI->TimerEnded.Broadcast();
	}
}
void AShooterGameMode::IncrementTeamScore(uint8 teamId)
{

}

void AShooterGameMode::OnTimerEnded()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	ShooterUI->RemoveFromParent();
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	GameOverWidget = CreateWidget<UGameOverWidget>(PC, GameOverWidgetClass);
	if (GameOverWidget)
	{
		GameOverWidget->AddToViewport();
		GameOverWidget->UpdateFinalScore(currentScore);
	}

	PC->SetShowMouseCursor(true);
	FInputModeUIOnly InputMode;
	PC->SetInputMode(InputMode);
}

