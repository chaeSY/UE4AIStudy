// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_SYFindNearestActor.generated.h"

/**
 * 
 */
UCLASS()
class SYAI_API UBTService_SYFindNearestActor : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_SYFindNearestActor();

private:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override final;


	// todo: private¿∏∑Œ πŸ≤‹ ∞Õ
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBlackboardKeySelector NearestActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName FindActorTag;
};
