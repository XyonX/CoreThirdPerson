// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AThirdPersonCharacter::AThirdPersonCharacter()
{
	SpringArm=CreateDefaultSubobject<USpringArmComponent>("Sprint Arm Component");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation=true;
	SpringArm->TargetArmLength=400;
	
	Camera=CreateDefaultSubobject<UCameraComponent>("Camera Component");
	Camera->SetupAttachment(SpringArm);

	GetCharacterMovement()->bOrientRotationToMovement =true;
}

// Called when the game starts or when spawned
void AThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
