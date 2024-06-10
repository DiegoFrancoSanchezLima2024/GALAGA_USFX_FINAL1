// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaTipo1.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCazaTipo1 : public ANaveEnemigaCaza
{
	GENERATED_BODY()
public:
	//virtual void Mover(float DeltaTime) override;
	virtual void Atacar() override;
	virtual void Destruir() override;
	virtual void Escapar() override;
	void Mover(float DeltaTime) override;

	float RunningTime;

	float SpeedScale;

	ANaveEnemigaCazaTipo1();
	FString Nombre_Nave;
};
