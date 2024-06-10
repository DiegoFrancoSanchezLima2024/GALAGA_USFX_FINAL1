// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodrizaBuqe.h"


void ANaveEnemigaNodrizaBuqe::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float NuevaX = -velocidad * DeltaTime;
	float NuevaY = 0;
	float NuevaZ = 215;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, NuevaZ);

	// Establece la nueva posición del actor
	SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaNodrizaBuqe::Atacar()
{
}

void ANaveEnemigaNodrizaBuqe::Destruir()
{
}

void ANaveEnemigaNodrizaBuqe::Escapar()
{
}