// Fill out your copyright notice in the Description page of Project Settings.
#include "SYCharacter.h"
#include "AIController.h"

TArray<ASYCharacter*> ASYCharacter::CharacterGroup;
int ASYCharacter::CurrentActivateOrder = 0;

// Sets default values
ASYCharacter::ASYCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASYCharacter::BeginPlay()
{
	Super::BeginPlay();

	CharacterGroup.Add(this);
	FollowOrder = (GroupOrder + 2) % 3;
	//temp
	CurrentActivateOrder = 0;
}

void ASYCharacter::BeginDestroy()
{
	CharacterGroup.Remove(this);
	Super::BeginDestroy();
}


// Called every frame
void ASYCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASYCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Z"), IE_Pressed, this, &ASYCharacter::NextCharcater);
}

void ASYCharacter::NextCharcater()
{
	// cache player controller
	AController* PlayerController = GetController();
	if (!PlayerController)
		return;

	CurrentActivateOrder = ++CurrentActivateOrder % 3;
	ASYCharacter* Character = GetCharacterFromGroup(CurrentActivateOrder);
	if (Character)
	{
		// possess next character
		PlayerController->UnPossess();
		PlayerController->Possess(Character);

		
		SpawnDefaultController();
	}
}

ASYCharacter* ASYCharacter::GetCharacterFromGroup(int order)
{
	for (auto Character : CharacterGroup)
	{
		if (Character->GroupOrder == order)
		{
			return Character;
		}
	}

	return nullptr;
}

ASYCharacter* ASYCharacter::GetFollowingCharacterFromGroup()
{
	for (auto Character : CharacterGroup)
	{
		if (Character->GroupOrder == FollowOrder)
		{
			return Character;
		}
	}

	return nullptr;
}