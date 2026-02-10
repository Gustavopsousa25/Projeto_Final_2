// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponentCPP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJETO_FINAL_2_API UHealthComponentCPP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponentCPP();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	int32 currentHealth;
	int32 MaxHealth;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
