// Fill out your copyright notice in the Description page of Project Settings.


#include "SYPlayerAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "SYCharacter.h"

ASYPlayerAIController::ASYPlayerAIController()
{
	BTComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BTComponent"));
}

void ASYPlayerAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	ASYCharacter* character = Cast<ASYCharacter>(InPawn);
	if (character)
	{
		if (BTComponent)
		{
			BTComponent->StartTree(*character->BT);
		}
	}
}

void ASYPlayerAIController::OnUnPossess()
{
	Super::OnUnPossess();
}
