// Daniel Alejandro Castro García <dandev237@gmail.com>

#include "InfiniteCaverns.h"
#include "RuntimeMeshActor.h"


// Sets default values
ARuntimeMeshActor::ARuntimeMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<URuntimeMeshComponent>(TEXT("Runtime Mesh"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void ARuntimeMeshActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARuntimeMeshActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ARuntimeMeshActor::CreateRuntimeMesh(const MeshData& Data)
{
	TArray<FRuntimeMeshVertexSimple> Vertices;
	TArray<int32> Triangles;

	for (FVector Vertex : Data.Vertices)
	{
		Vertices.Add(FRuntimeMeshVertexSimple(Vertex));
	}

	for (int32 TriangleVertex : Data.Triangles)
	{
		Triangles.Add(TriangleVertex);
	}

	// Create the mesh section  (also enables collision, and sets the section update frequency to infrequent)
	MeshComponent->CreateMeshSection(0, Vertices, Triangles, true);
}