/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "CoreGameManager/GameModes/CoreGameMode.h"
#include "ThirdPersonGameMode.generated.h"

UCLASS(Blueprintable)
class CORETHIRDPERSON_API AThirdPersonGameMode : public ACoreGameMode
{
	GENERATED_BODY()

public:
	AThirdPersonGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};