// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SYFindNearestActor.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

UBTService_SYFindNearestActor::UBTService_SYFindNearestActor()
	:Super()
{
	NodeName = "FindNearestActor";
	NearestActor.AddObjectFilter(this, FName(TEXT("NearestActor")), AActor::StaticClass());
}

void UBTService_SYFindNearestActor::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	AController* Controller = OwnerComp.GetOwner<AController>();
	if (!Controller)
		return;

	APawn* Pawn = Controller->GetPawn();
	if (!Pawn)
		return;

	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (!BB)
		return;

	FVector MyPos = Pawn->K2_GetActorLocation();
	float	ClosestDistance = FLT_MAX;

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FindActorTag, Actors);
	
	for (auto Actor : Actors)
	{
		FVector TargetPos = Actor->K2_GetActorLocation();

		float distance = FVector::Distance(MyPos, TargetPos);
		if (distance < ClosestDistance)
		{
			BB->SetValueAsObject(NearestActor.SelectedKeyName, Actor);
		}
	}
}
