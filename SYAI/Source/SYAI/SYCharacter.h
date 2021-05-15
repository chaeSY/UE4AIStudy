// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SYCharacter.generated.h"

class AAIController;

UCLASS()
class SYAI_API ASYCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASYCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override ;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void NextCharcater();

	//virtual void PossessedBy(AController* NewController) override;
	//virtual void UnPossessed() override;
	// virtual void UnPossessed(); //pawn


	UPROPERTY(Category = "GroupOrder", EditAnywhere, BlueprintReadWrite)
	int GroupOrder = 0;

public:
	UPROPERTY(Category = "AI", EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AAIController> ACClass;

	UPROPERTY(Category = "AI", EditAnywhere, BlueprintReadWrite)
	AAIController* AC;

	UPROPERTY(Category = "AI", EditAnywhere, BlueprintReadWrite)
	class UBehaviorTree* BT;

private:
	// @#todo: player character를 관리하는 매니저를 따로 두는게 좋아보임
	static TArray<ASYCharacter*> CharacterGroup;
	static int CurrentActivateOrder;
};
