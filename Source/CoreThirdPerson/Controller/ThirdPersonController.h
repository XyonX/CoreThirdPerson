/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "CorePlayer/Player/CorePlayerController.h"
#include "ThirdPersonController.generated.h"

/**
 * 
 */
UCLASS()
class CORETHIRDPERSON_API AThirdPersonController : public ACorePlayerController
{
	GENERATED_BODY()
public:
	
	AThirdPersonController();
	
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
};
