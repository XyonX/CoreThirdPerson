// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonController.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"


AThirdPersonController::AThirdPersonController()
{
	DefaultMovementData.TurnRate=1;
	DefaultMovementData.LookUpRate=1;
	MovementData=DefaultMovementData;
}

void AThirdPersonController::BeginPlay()
{
	Super::BeginPlay();
	ThirdPersonCharacter= Cast<AThirdPersonCharacter>(GetPawn());
	
	if(ThirdPersonCharacter==nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Third Person Character found Found");
		FGenericPlatformMisc::RequestExit(false);
	}
	

	// Load a different level to exit the game (e.g., main menu or exit screen level)
	//UGameplayStatics::OpenLevel(this, "MainMenuLevel"); // Replace "MainMenuLevel" with the name of your desired exit screen level
	
	// Request the application to exit gracefully
	
}

/** Normal Input system functions */

void AThirdPersonController::OnMouseMoveXAxis(float Value)
{
	AddYawInput(Value*GetWorld()->DeltaTimeSeconds*MovementData.TurnRate);
}

void AThirdPersonController::OnMouseMoveYAxis(float Value)
{
	AddPitchInput(Value*GetWorld()->DeltaTimeSeconds*MovementData.LookUpRate);
}

/** Enhanced Input Functions */

void AThirdPersonController::OnMovement(const FInputActionValue& Value)
{
	UPawnMovementComponent*MovementComponent = ThirdPersonCharacter->GetMovementComponent();

	FRotator CtrlRotation = GetControlRotation();
	FRotator YawRot(0.0f, CtrlRotation.Yaw, 0.f);
	
	FVector ForwardDirection = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);


	MovementComponent->AddInputVector(ForwardDirection*Value[0]);
	MovementComponent->AddInputVector(RightDirection*Value[1]);
	
	//MovementComponent->AddInputVector(ForwardDirection * (Value[0] != 0.0f));
	//MovementComponent->AddInputVector(RightDirection * (Value[1] != 0.0f));
}

void AThirdPersonController::OnLookUp(const FInputActionValue& Value)
{
	AddYawInput(Value[0]*GetWorld()->DeltaTimeSeconds*MovementData.TurnRate);
	AddPitchInput(Value[1]*GetWorld()->DeltaTimeSeconds*MovementData.LookUpRate);
	
}

void AThirdPersonController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("MouseX"), this, &AThirdPersonController::OnMouseMoveXAxis);
	InputComponent->BindAxis(TEXT("MouseY"), this, &AThirdPersonController::OnMouseMoveYAxis);


	UEnhancedInputComponent* EnhancedInputComp =Cast <UEnhancedInputComponent>(InputComponent);
	if(IsValid(EnhancedInputComp))
	{
		if(MovementAction)
		{
			EnhancedInputComp->BindAction(	MovementAction,ETriggerEvent::Triggered,this,&AThirdPersonController::OnMovement);
		}
		if(LookUpAction)
		{
			EnhancedInputComp->BindAction(	LookUpAction,ETriggerEvent::Triggered,this,&AThirdPersonController::OnLookUp);
		}
	}


	
	
}
