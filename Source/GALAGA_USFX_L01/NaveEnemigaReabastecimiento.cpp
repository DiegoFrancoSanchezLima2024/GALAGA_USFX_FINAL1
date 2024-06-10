// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaReabastecimiento.h"

// Called when the game starts or when spawned
void ANaveEnemigaReabastecimiento::BeginPlay()
{
	Super::BeginPlay();

}

ANaveEnemigaReabastecimiento::ANaveEnemigaReabastecimiento()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel4.EnemyLevel4'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	velocidad = 300;

	SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));

	SetActorRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));

	Nombre_Nave = "NaveReabastecimiento";


}

// Called every frame
void ANaveEnemigaReabastecimiento::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}



void ANaveEnemigaReabastecimiento::Atacar()
{

}

void ANaveEnemigaReabastecimiento::Destruir()
{

}

void ANaveEnemigaReabastecimiento::Escapar()
{

}

void ANaveEnemigaReabastecimiento::Mover(float DeltaTime)
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
	if (NuevaPosicion.X < limiteInferiorX)
	{
		SetActorLocation(FVector(1400.0f, NuevaPosicion.Y, NuevaPosicion.Z));
	}

}

// void ANaveEnemigaCaza::MoverAleatoriamente(float DeltaTime)
// {
// 	// Obtiene la posición actual del actor
// 	FVector PosicionActual = GetActorLocation();

// 	// Genera nuevas coordenadas X e Y aleatorias
// 	float NuevaX = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;
// 	float NuevaY = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;

// 	// Crea un nuevo vector de posición con las coordenadas aleatorias y la misma Z que la posición actual
// 	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

// 	// Establece la nueva posición del actor
// 	SetActorLocation(NuevaPosicion);
// }

