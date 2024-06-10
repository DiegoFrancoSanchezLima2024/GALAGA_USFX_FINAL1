// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaEspia.h"

// Constructor
ANaveEnemigaEspia::ANaveEnemigaEspia()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/Nodriza2.Nodriza2'"));
    mallaNaveEnemiga->SetStaticMesh(Malla.Object); // Aqu� estaba el error

    velocidad = 0;
    AmplitudZigZag = 40.0f;
    Frequency = 8.0f;
    TiempoTranscurrido = 0.0f;

    Nombre_Nave = "NaveEspia";


    SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));
    SetActorRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
}

// Called when the game starts or when spawned
void ANaveEnemigaEspia::BeginPlay()
{
    Super::BeginPlay();
    // L�gica de inicio espec�fica de las naves esp�as
}

// Called every frame
void ANaveEnemigaEspia::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Mover(DeltaTime);
    // L�gica de actualizaci�n espec�fica de las naves esp�as
}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
    // Obt�n la posici�n actual de la nave
    FVector PosicionActual = GetActorLocation();

    // Calcula el desplazamiento en el eje Y basado en el tiempo y una amplitud
    float DesplazamientoY = AmplitudZigZag * FMath::Sin(Frequency * TiempoTranscurrido);

        // Calcula el desplazamiento en el eje X
        float DesplazamientoX = -velocidad * DeltaTime;

    float DesplazamientoZ = AmplitudZigZag * FMath::Sin(Frequency * TiempoTranscurrido);

    // Calcula la nueva posici�n
    FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX , PosicionActual.Y + DesplazamientoY, PosicionActual.Z);

    // Establece la nueva posici�n del actor
    SetActorLocation(NuevaPosicion);

    // Actualiza el tiempo transcurrido para el movimiento en zigzag
    TiempoTranscurrido += DeltaTime;

    // Si la nave alcanza el l�mite inferior en X, reinicia su posici�n
    if (NuevaPosicion.X < limiteInferiorX)
    {
        SetActorLocation(FVector(limiteSuperiorX, NuevaPosicion.Y, NuevaPosicion.Z));
        TiempoTranscurrido = 0.0f; // Reinicia el tiempo transcurrido
    }
}

void ANaveEnemigaEspia::Atacar()
{
    // L�gica de ataque espec�fica de las naves esp�as
}

void ANaveEnemigaEspia::Destruir()
{
    // L�gica de destrucci�n espec�fica de las naves esp�as
}

void ANaveEnemigaEspia::Escapar()
{
    // L�gica de escape espec�fica de las naves esp�as
}

