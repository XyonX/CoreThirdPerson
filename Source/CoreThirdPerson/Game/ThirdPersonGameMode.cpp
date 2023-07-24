// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonGameMode.h"
#include "CoreThirdPerson/Character/ThirdPersonCharacter.h"
#include "CoreThirdPerson/Controller/ThirdPersonController.h"


AThirdPersonGameMode::AThirdPersonGameMode(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer)
{
	
	DefaultPawnClass=AThirdPersonCharacter::StaticClass();
	PlayerControllerClass=AThirdPersonController::StaticClass();
}
