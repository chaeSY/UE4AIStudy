// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_SYCalcDistance.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

UBTService_SYCalcDistance::UBTService_SYCalcDistance()
	:Super()
{
	NodeName = "CalcDistance";
	Target.AddObjectFilter(this, FName(TEXT("Target")), AActor::StaticClass());
	DistanceToTarget.AddFloatFilter(this, FName(TEXT("DistanceToTarget")));
}

void UBTService_SYCalcDistance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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

	AActor* TargetActor = Cast<AActor>(BB->GetValueAsObject(Target.SelectedKeyName));
	if (!TargetActor)
		return;

	FVector TargetPos = TargetActor->K2_GetActorLocation();
	FVector MyPos = Pawn->K2_GetActorLocation();
	float Distance = FVector::Distance(MyPos, TargetPos);
	BB->SetValueAsFloat(DistanceToTarget.SelectedKeyName, Distance);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%f"), Distance));
}
