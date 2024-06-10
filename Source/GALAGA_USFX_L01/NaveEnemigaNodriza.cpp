#include "NaveEnemigaNodriza.h"
#include "GALAGA_USFX_L01Projectile.h"

// Called when the game starts or when spawned
void ANaveEnemigaNodriza::BeginPlay()
{
	Super::BeginPlay();

}

ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{

	PrimaryActorTick.bCanEverTick = true;


	// Asigna la malla de la nave enemiga
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel5.EnemyLevel5'"));
	if (malla.Succeeded())
	{
		mallaNaveEnemiga->SetStaticMesh(malla.Object);
	}

	// Inicializa la velocidad de movimiento
	velocidad = 500;

	SetActorRotation(FRotator(0.0f, 180.0f, 0.0f));

	SetActorRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));

	Nombre_Nave = "NaveNodriza";
}

// Called every frame
void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaNodriza::Atacar()
{
	// Lógica de ataque
}

void ANaveEnemigaNodriza::Destruir()
{

}

void ANaveEnemigaNodriza::Escapar()
{
	// Lógica de escape
}

void ANaveEnemigaNodriza::Mover(float DeltaTime)
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


void ANaveEnemigaNodriza::DestruirNaveEnemigaNodriza()
{
	// Destruir la nave enemiga nodriza
	Destroy();
}
