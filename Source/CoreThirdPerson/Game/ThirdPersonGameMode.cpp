/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/


#include "ThirdPersonGameMode.h"
#include "CoreThirdPerson/Character/ThirdPersonCharacter.h"
#include "CoreThirdPerson/Controller/ThirdPersonController.h"


AThirdPersonGameMode::AThirdPersonGameMode(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer)
{
	
	DefaultPawnClass=AThirdPersonCharacter::StaticClass();
	PlayerControllerClass=AThirdPersonController::StaticClass();
}
