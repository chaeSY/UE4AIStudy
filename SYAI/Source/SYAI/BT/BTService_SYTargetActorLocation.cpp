// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SYTargetActorLocation.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../SYCharacter.h"

UBTService_SYTargetActorLocation::UBTService_SYTargetActorLocation()
	:Super()
{
	NodeName = "SYTargetActorLocation";

	TargetLocation.AddVectorFilter(this, FName(TEXT("TargetLocation")));
	TargetActor.AddObjectFilter(this, FName(TEXT("TargetActor")), ASYCharacter::StaticClass());
}

void UBTService_SYTargetActorLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (BB)
	{
		UObject* obj = BB->GetValueAsObject(TargetActor.SelectedKeyName);
		ASYCharacter* Character = Cast<ASYCharacter>(BB->GetValueAsObject(TargetActor.SelectedKeyName));
		if (Character)
		{
			BB->SetValueAsVector(TargetLocation.SelectedKeyName, Character->GetActorLocation());
		}
	}
}
