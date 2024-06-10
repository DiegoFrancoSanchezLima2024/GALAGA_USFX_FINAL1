// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaTipo2.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCazaTipo2 : public ANaveEnemigaCaza
{
	GENERATED_BODY()
public:
	virtual void Mover(float DeltaTime) override;
	virtual void Atacar() override;
	virtual void Destruir() override;
	virtual void Escapar() override;
    float RunningTime;
    float SpeedScale;

	ANaveEnemigaCazaTipo2();

	FVector PosicionInicial;
	
	virtual void BeginPlay() override;
	FString Nombre_Nave;
};
