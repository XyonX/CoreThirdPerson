// MyAnimInstance.h

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CorePlugin/Data/AnimationData.h"
#include "ThirdPersonAnimInstance.generated.h"


struct FThirdPersonAnimInstanceProxy;

UCLASS()
class CORETHIRDPERSON_API UThirdPersonAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UThirdPersonAnimInstance();

	//Function only called at the starting
	virtual void NativeInitializeAnimation() override;

	//Ignore this function to Increase performance
	// Called every frame
	//virtual void NativeUpdateAnimation(float DeltaTime) override;
	void Receiver_AnimationData (FAnimationData InAnimData);

	// Function to update animation data
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void UpdateAnimationData(FAnimationData InAnimationData);
	
protected:

	/** Default Animation data to start with */
	FAnimationData DefaultAnimationData;
	
	// Animation data that can be accessed from Blueprint
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	FAnimationData AnimationData;

	TSharedPtr<FThirdPersonAnimInstanceProxy>Proxy;
};

