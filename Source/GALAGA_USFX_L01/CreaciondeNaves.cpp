// Fill out your copyright notice in the Description page of Project Settings.


#include "CreaciondeNaves.h"
#include "NaveEnemiga.h"

// Sets default values
ACreaciondeNaves::ACreaciondeNaves()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ANaveEnemiga* ACreaciondeNaves::getNaves(FString TypeNave)
{
	ANaveEnemiga* Nave = MakeNave(TypeNave);
	return nullptr;
}

// Called when the game starts or when spawned
void ACreaciondeNaves::BeginPlay()
{
	//Super::BeginPlay();
	
}

// Called every frame
void ACreaciondeNaves::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

}

