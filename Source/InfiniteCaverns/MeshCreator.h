// Daniel Alejandro Castro Garc�a <dandev237@gmail.com>

#pragma once

/**
*
*/
struct INFINITECAVERNS_API Node
{
	FVector	Position{ 0.0f, 0.0f, 0.0f };
	int32	Index{ -1 };

	Node() {};
	Node(FVector _Pos);
};

struct INFINITECAVERNS_API ControlNode : Node
{
	bool Active;
	Node Above, Right;

	ControlNode() {};
	ControlNode(FVector _Pos, bool _Active, float Size);
};

struct INFINITECAVERNS_API Square
{
	ControlNode TopLeft, TopRight, BottomLeft, BottomRight;
	Node Left, Right, Top, Bottom;
	int32 SquareConfiguration{ 0 };		//4 bit number representing 16 possible Marching Squares configurations

	Square() {};
	Square(ControlNode _TopLeft, ControlNode _TopRight, ControlNode _BottomLeft, ControlNode _BottomRight);
};

struct INFINITECAVERNS_API SquareGrid
{
	TArray<TArray <Square>> SquaresGrid;

	SquareGrid() {};
	SquareGrid(const TArray<int32, FDefaultAllocator> &Map, const float & Size, const int32 &Width, const int32 &Height);
};

class INFINITECAVERNS_API MeshCreator
{
private:
	SquareGrid MeshGrid;

public:
	TArray<FVector> Vertices;
	TArray<int32> Triangles;	//Each triangle is defined by a three consecutive integers (vertices in clockwise order)

	MeshCreator() {};
	~MeshCreator() {};

	void CalculateTrianglesForMesh(const TArray<int32> &Map, const float & Size, const int32 &Width, const int32 &Height);

	void TriangulateSquare(const Square &Square);

	void MeshFromPoints(TArray<Node> &Points);

	void TriangleFromVertices(const int32& Vertex1, const int32& Vertex2, const int32& Vertex3);

};
