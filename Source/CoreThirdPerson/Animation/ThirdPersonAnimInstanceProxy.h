#pragma once

#include "CoreMinimal.h"
#include "ThirdPersonAnimInstance.h"
#include "Animation/AnimInstanceProxy.h"
#include "ThirdPersonAnimInstanceProxy.generated.h"

// Create a custom AnimInstanceProxy struct
USTRUCT()
struct CORETHIRDPERSON_API FThirdPersonAnimInstanceProxy : public FAnimInstanceProxy
{
	GENERATED_BODY()

public:
	// Constructor
	FThirdPersonAnimInstanceProxy();
	FThirdPersonAnimInstanceProxy(UAnimInstance* InAnimInstance);

	// Function to update the animation data from the game thread
	void UpdateAnimationData(const FMyAnimationData& NewAnimationData);

	// Override the FAnimInstanceProxy functions if needed
	// For example, you can override Update, GatherBonesToUpdate, etc.

	protected:
	// Animation data that can be accessed from the rendering thread
	FMyAnimationData AnimationData;

	// Add more animation-related variables and functions as needed
};