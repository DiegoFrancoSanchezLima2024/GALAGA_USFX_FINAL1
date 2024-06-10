// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaCazaTipo2.h"

void ANaveEnemigaCazaTipo2::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();

	// Genera nuevas coordenadas X e Y aleatorias
	float NuevaX = -200* DeltaTime;
	float NuevaY = -velocidad* DeltaTime;

	float NuevaZ = 212;

	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, NuevaZ);

	// Establece la nueva posición del actor
	SetActorLocation(NuevaPosicion);

	if (NuevaPosicion.X < limiteInferiorX)
	{
		//SetActorLocation(PosicionInicial);
		//NuevaPosicion *= -1;
		//SetActorLocation(NuevaPosicion);
		
	}

}


void ANaveEnemigaCazaTipo2::Atacar()
{
}

void ANaveEnemigaCazaTipo2::Destruir()
{
}

void ANaveEnemigaCazaTipo2::Escapar()
{
}

ANaveEnemigaCazaTipo2::ANaveEnemigaCazaTipo2()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallanave(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel1.EnemyLevel1'"));
	mallaNaveEnemiga->SetStaticMesh(mallanave.Object);

	SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));

	mallaNaveEnemiga->SetRelativeScale3D(FVector(2.f, 2.f, 2.f));

	velocidad = 300;

	Nombre_Nave = "NaveCazatipo2";

}

void ANaveEnemigaCazaTipo2::BeginPlay()
{
	Super::BeginPlay();

	PosicionInicial = GetActorLocation();
}

