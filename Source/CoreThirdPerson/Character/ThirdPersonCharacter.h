// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "ThirdPersonCharacter.generated.h"

UCLASS()
class CORETHIRDPERSON_API AThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	USpringArmComponent*SpringArm;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Components")
	UCameraComponent*Camera;
};
