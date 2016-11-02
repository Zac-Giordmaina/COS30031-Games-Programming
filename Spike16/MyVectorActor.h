// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyVectorActor.generated.h"

UCLASS()
class CUSTOMBP_API AMyVectorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyVectorActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    UFUNCTION(Category="My Vector Functions")
    void setX(float value);
    UFUNCTION(Category="My Vector Functions")
    void setY(float value);
    UFUNCTION(Category="My Vector Functions")
    void setZ(float value);
    UFUNCTION(Category="My Vector Functions")
    float getX();
    UFUNCTION(Category="My Vector Functions")
    float getY();
    UFUNCTION(Category="My Vector Functions")
    float getZ();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="My Vector Variables")
    float Xvar;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="My Vector Variables")
    float Yvar;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="My Vector Variables")
    float Zvar;
	
};
