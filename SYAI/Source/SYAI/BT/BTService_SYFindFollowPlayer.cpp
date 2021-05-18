// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SYFindFollowPlayer.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../SYCharacter.h"
#include "AIController.h"

UBTService_SYFindFollowPlayer::UBTService_SYFindFollowPlayer()
	:Super()
{
	NodeName = "FindFollowPlayer";

	FollowPlayer.AddObjectFilter(this, FName(TEXT("FollowPlayer")), ASYCharacter::StaticClass());
}

void UBTService_SYFindFollowPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (BB)
	{
		AAIController* AIController = Cast<AAIController>(OwnerComp.GetOwner());
		if (AIController)
		{
			ASYCharacter* Character = Cast<ASYCharacter>(AIController->GetPawn());
			if (Character)
			{
				BB->SetValueAsObject(FollowPlayer.SelectedKeyName, Character->GetFollowingCharacterFromGroup());
			}
		}
	}
}
