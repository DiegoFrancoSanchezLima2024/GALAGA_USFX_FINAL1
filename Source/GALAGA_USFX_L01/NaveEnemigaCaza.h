// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.generated.h"


UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaCaza : public ANaveEnemiga
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ANaveEnemigaCaza();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	virtual void Mover(float DeltaTime);
	virtual void Atacar( );
	virtual void Destruir( );
	virtual void Escapar( );

	float RunningTime;

	float SpeedScale;

	float Tiempo_Disparo;
	float Tiempo_Disparo_Generar;
	FVector Distancia_Disparo;

	FString Nombre_Nave;

};
	
