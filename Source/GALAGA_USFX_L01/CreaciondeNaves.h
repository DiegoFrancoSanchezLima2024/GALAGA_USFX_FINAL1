// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "CreaciondeNaves.generated.h"

UCLASS()
class GALAGA_USFX_L01_API ACreaciondeNaves : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACreaciondeNaves();


	ANaveEnemiga* getNaves(FString TypeNave);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Funcion pura virtual
	virtual ANaveEnemiga* MakeNave(FString TypeNave) PURE_VIRTUAL(CreaciondeNaves::MakeNave, return nullptr;);
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
