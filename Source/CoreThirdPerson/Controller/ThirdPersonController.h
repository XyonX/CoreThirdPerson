// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "CorePlugin/Data/AnimationData.h"
#include "CorePlugin/Data/CharacterMovementData.h"
#include "CoreThirdPerson/Character/ThirdPersonCharacter.h"
#include "GameFramework/PlayerController.h"
#include "ThirdPersonController.generated.h"

/**
 * 
 */
UCLASS()
class CORETHIRDPERSON_API AThirdPersonController : public APlayerController
{
	GENERATED_BODY()
public:
	
	AThirdPersonController();
	
	virtual void BeginPlay() override;
	

	//Normal Input system 

	void OnMouseMoveXAxis (float Value);
	void OnMouseMoveYAxis (float Value);

	void OnMovement (const FInputActionValue& Value);
	void OnLookUp (const FInputActionValue& Value);
	
	
	virtual void SetupInputComponent() override;


protected:


	
	/** Defaults   */
	/** Exposed to set Default Values* */

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Defaults")
	FCharacterMovementData DefaultMovementData;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Defaults")
	class UInputAction* MovementAction ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Defaults")
	class UInputAction* LookUpAction ;


	/** Not Supposed to expose to Designer for internal use only */

	UPROPERTY()
	AThirdPersonCharacter* ThirdPersonCharacter;

	FAnimationData AnimationData;
	FCharacterMovementData MovementData;
};
