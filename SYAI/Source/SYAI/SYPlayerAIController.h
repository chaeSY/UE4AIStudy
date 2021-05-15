// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SYPlayerAIController.generated.h"

/**
 * 
 */
UCLASS()
class SYAI_API ASYPlayerAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ASYPlayerAIController();

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBehaviorTreeComponent* BTComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBlackboardComponent* BBComponent;
};
