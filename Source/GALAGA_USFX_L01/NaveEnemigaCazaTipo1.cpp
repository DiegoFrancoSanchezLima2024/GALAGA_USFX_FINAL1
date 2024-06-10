// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCazaTipo1.h"

void ANaveEnemigaCazaTipo1::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float NuevaX = -velocidad * DeltaTime;
	float NuevaY = 0;
	float NuevaZ = 215;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	FVector NuevaPosicion = FVector( PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, NuevaZ);

	// Establece la nueva posición del actor
	SetActorLocation(NuevaPosicion);
	if (NuevaPosicion.X < limiteInferiorX)
	{
		SetActorLocation(FVector(1774.463989f, NuevaPosicion.Y, NuevaPosicion.Z));
	}

}

void ANaveEnemigaCazaTipo1::Atacar()
{
}

void ANaveEnemigaCazaTipo1::Destruir()
{
}

void ANaveEnemigaCazaTipo1::Escapar()
{
}

ANaveEnemigaCazaTipo1::ANaveEnemigaCazaTipo1()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallanave(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel2.EnemyLevel2'"));
	mallaNaveEnemiga->SetStaticMesh(mallanave.Object);

	SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));

	SetActorRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));

	velocidad = 500;

	Nombre_Nave = "NaveCazaTipo1";

}
