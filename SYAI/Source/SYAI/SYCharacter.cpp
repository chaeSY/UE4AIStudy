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

	if (ACClass)
	{
		//StaticConstructObject
		NewObject<AAIController>(AC, ACClass, TEXT("AC"));
	}

}

// Called when the game starts or when spawned
void ASYCharacter::BeginPlay()
{
	Super::BeginPlay();

	CharacterGroup.Add(this);

	if (ACClass)
	{
		//StaticConstructObject
		AC = NewObject<AAIController>(GetWorld(), ACClass, TEXT("AC"));
	}

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
	AController* c = GetController();

	CurrentActivateOrder = ++CurrentActivateOrder % 3;
	//UnPossessed();
	//
	//if(AC)
	//	Possesse(AC);
	
	for (auto Character : CharacterGroup)
	{
		if (Character->GroupOrder == CurrentActivateOrder)
		{
			//Character->AC->UnPossess();
			c->UnPossess();
			AC->Possess(this);
			//c->Possess(Character);
			break;
		}
	}
}
