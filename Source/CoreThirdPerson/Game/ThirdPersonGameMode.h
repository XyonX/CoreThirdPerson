// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ThirdPersonGameMode.generated.h"

UCLASS(Blueprintable)
class CORETHIRDPERSON_API AThirdPersonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AThirdPersonGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};