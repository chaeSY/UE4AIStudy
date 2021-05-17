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
	ASYCharacter();

protected:
	virtual void BeginPlay() override ;
	virtual void BeginDestroy() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void NextCharcater();

	UPROPERTY(Category = "CharacterGroup", EditAnywhere, BlueprintReadWrite)
	int GroupOrder = 0;

	UPROPERTY(Category = "CharacterGroup", EditAnywhere, BlueprintReadWrite)
	int FollowOrder = 0;

	UPROPERTY(Category = "AI", EditAnywhere, BlueprintReadWrite)
	class UBehaviorTree* BT;


public:
	UFUNCTION(Category = "CharacterGroup", BlueprintCallable)
	ASYCharacter* GetCharacterFromGroup(int order);

	UFUNCTION(Category = "CharacterGroup", BlueprintCallable)
	ASYCharacter* GetFollowingCharacterFromGroup();

private:
	// @#todo: player character를 관리하는 매니저를 따로 두는게 좋아보임
	static TArray<ASYCharacter*> CharacterGroup;
	static int CurrentActivateOrder;
};
