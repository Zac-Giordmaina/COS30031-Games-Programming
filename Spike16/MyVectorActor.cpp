// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomBP.h"
#include "MyVectorActor.h"


// Sets default values
AMyVectorActor::AMyVectorActor()
{
//    Xvar = 0;
//    Yvar = 0;
//    Zvar = 0;

}

// Called when the game starts or when spawned
void AMyVectorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyVectorActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AMyVectorActor::setX(float value){
    Xvar = value;
}

void AMyVectorActor::setY(float value){
    Yvar = value;
}

void AMyVectorActor::setZ(float value){
    Zvar = value;
}

float AMyVectorActor::getX(){
    return Xvar;
}

float AMyVectorActor::getY(){
    return Yvar;
}

float AMyVectorActor::getZ(){
    return Zvar;
}
