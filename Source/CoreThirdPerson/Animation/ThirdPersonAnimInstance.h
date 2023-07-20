// MyAnimInstance.h

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ThirdPersonAnimInstance.generated.h"

USTRUCT(BlueprintType)
struct FMyAnimationData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumping;

	// Add more animation-related variables as needed
};

UCLASS()
class CORETHIRDPERSON_API UThirdPersonAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UThirdPersonAnimInstance();

	// Called every frame
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	// Function to update animation data
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void UpdateAnimationData(float Speed, bool bJumping);

protected:
	// Animation data that can be accessed from Blueprint
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Animation")
	FMyAnimationData AnimationData;

	// Add more animation-related variables and functions as needed
};
