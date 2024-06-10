// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "Kismet/GameplayStatics.h"
#include "GALAGA_USFX_L01Projectile.h"
#include "Engine/InstancedStaticMesh.h"


// Called when the game starts or when spawned
void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();

}

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel2.EnemyLevel2'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	velocidad = 100;

	SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));

	SetActorRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));

	Tiempo_Disparo = 0;
	Tiempo_Disparo_Generar = 0;
	Distancia_Disparo = FVector(90.f, 0.f, 0.f);

	Nombre_Nave = "NaveCaza";
}



// Called every frame
void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Contador de tiempo para el disparo
	Tiempo_Disparo += DeltaTime;
	if (Tiempo_Disparo >= Tiempo_Disparo_Generar) {
		Tiempo_Disparo = 0.f;

		// Declaraci�n de la direcci�n y rotaci�n del primer proyectil
		const FVector Direccion_Disparo = FVector(-1.f, 0.f, 0.f);
		const FRotator Rotacion_Disparo = Direccion_Disparo.Rotation();
		const FVector Ubicacion_Disparo = GetActorLocation() + Rotacion_Disparo.RotateVector(Distancia_Disparo);

		// Desplazamientos adicionales para los proyectiles restantes
		const float DesplazamientoEntreProyectiles = 50.f; // Ajusta seg�n sea necesario
		const FVector DesplazamientoAdicional = FVector(0.f, DesplazamientoEntreProyectiles, 0.f);

		// Verificaci�n de si el mundo no est� vac�o
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			// Spawn de los tres proyectiles
			World->SpawnActor<AGALAGA_USFX_L01Projectile>(Ubicacion_Disparo, Rotacion_Disparo);
		}
	}
}




void ANaveEnemigaCaza::Atacar()
{

}

void ANaveEnemigaCaza::Destruir()
{

}

void ANaveEnemigaCaza::Escapar()
{
		
}

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();

	// Calcula el desplazamiento en el eje X
	float DesplazamientoX = -velocidad * DeltaTime;

	// Calcula la nueva posici�n en el eje X
	float NuevaX = PosicionActual.X + DesplazamientoX;

	// Crea un nuevo vector de posici�n manteniendo las coordenadas Y y Z y actualizando X
	FVector NuevaPosicion = FVector(NuevaX, PosicionActual.Y, PosicionActual.Z);

	// Establece la nueva posici�n del actor
	SetActorLocation(NuevaPosicion);

	// Si la nave se sale del l�mite inferior en el eje X, la coloca de nuevo en la posici�n inicial
	if (NuevaX < limiteInferiorX)
	{
		SetActorLocation(FVector(limiteSuperiorX, PosicionActual.Y, PosicionActual.Z));
	}
}


// void ANaveEnemigaCaza::MoverAleatoriamente(float DeltaTime)
// {
// 	// Obtiene la posici�n actual del actor
// 	FVector PosicionActual = GetActorLocation();

// 	// Genera nuevas coordenadas X e Y aleatorias
// 	float NuevaX = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;
// 	float NuevaY = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;

// 	// Crea un nuevo vector de posici�n con las coordenadas aleatorias y la misma Z que la posici�n actual
// 	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

// 	// Establece la nueva posici�n del actor
// 	SetActorLocation(NuevaPosicion);
// }