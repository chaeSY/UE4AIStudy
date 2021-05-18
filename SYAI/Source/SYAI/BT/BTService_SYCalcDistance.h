// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_SYCalcDistance.generated.h"

/**
 * 
 */
UCLASS()
class SYAI_API UBTService_SYCalcDistance : public UBTService
{
	GENERATED_BODY()

public:
	UBTService_SYCalcDistance();

private:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override final;


	// todo: private���� �ٲ� ��
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBlackboardKeySelector Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBlackboardKeySelector DistanceToTarget;
};
