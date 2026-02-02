// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJETO_FINAL_2_API UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
	public : 
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Components", meta = (BindWidget))
		TObjectPtr<UProgressBar> HealthProgressBar;
	
};
