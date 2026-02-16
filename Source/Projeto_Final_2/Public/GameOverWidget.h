// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h" 

/**
 * 
 */
UCLASS(abstract)
class PROJETO_FINAL_2_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Shooter")
	void UpdateFinalScore(int32 Score);
};
