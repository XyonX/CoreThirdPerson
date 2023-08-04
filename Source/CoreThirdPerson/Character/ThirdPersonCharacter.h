/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "CorePlayer/Character/CoreCharacter.h"
#include "ThirdPersonCharacter.generated.h"


UCLASS()
class CORETHIRDPERSON_API AThirdPersonCharacter : public ACoreCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
};
