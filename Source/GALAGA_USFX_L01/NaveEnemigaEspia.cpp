// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaEspia.h"

// Constructor
ANaveEnemigaEspia::ANaveEnemigaEspia()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/Nodriza2.Nodriza2'"));
    mallaNaveEnemiga->SetStaticMesh(Malla.Object); // Aquí estaba el error

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
    // Lógica de inicio específica de las naves espías
}

// Called every frame
void ANaveEnemigaEspia::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Mover(DeltaTime);
    // Lógica de actualización específica de las naves espías
}

void ANaveEnemigaEspia::Mover(float DeltaTime)
{
    // Obtén la posición actual de la nave
    FVector PosicionActual = GetActorLocation();

    // Calcula el desplazamiento en el eje Y basado en el tiempo y una amplitud
    float DesplazamientoY = AmplitudZigZag * FMath::Sin(Frequency * TiempoTranscurrido);

        // Calcula el desplazamiento en el eje X
        float DesplazamientoX = -velocidad * DeltaTime;

    float DesplazamientoZ = AmplitudZigZag * FMath::Sin(Frequency * TiempoTranscurrido);

    // Calcula la nueva posición
    FVector NuevaPosicion = FVector(PosicionActual.X + DesplazamientoX , PosicionActual.Y + DesplazamientoY, PosicionActual.Z);

    // Establece la nueva posición del actor
    SetActorLocation(NuevaPosicion);

    // Actualiza el tiempo transcurrido para el movimiento en zigzag
    TiempoTranscurrido += DeltaTime;

    // Si la nave alcanza el límite inferior en X, reinicia su posición
    if (NuevaPosicion.X < limiteInferiorX)
    {
        SetActorLocation(FVector(limiteSuperiorX, NuevaPosicion.Y, NuevaPosicion.Z));
        TiempoTranscurrido = 0.0f; // Reinicia el tiempo transcurrido
    }
}

void ANaveEnemigaEspia::Atacar()
{
    // Lógica de ataque específica de las naves espías
}

void ANaveEnemigaEspia::Destruir()
{
    // Lógica de destrucción específica de las naves espías
}

void ANaveEnemigaEspia::Escapar()
{
    // Lógica de escape específica de las naves espías
}

