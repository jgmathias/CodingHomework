template<class VertexType>
class GraphType
{
public:
	GraphType();                  // Default of 50 vertices
	GraphType(int maxV);          // maxV <= 50
	~GraphType();
	void AddVertex(VertexType);
	void AddEdge(VertexType, VertexType, int);
	int WeightIs(VertexType, VertexType);

	bool EdgeExists(VertexType, VertexType);
	void DeleteEdge(VertexType, VertexType);

private:
	int numVertices;
	int maxVertices;
	VertexType* vertices;
	int edges[50][50];
};

template<class VertexType>
GraphType<VertexType>::GraphType()
{
	numVertices = 0;
	maxVertices = 50;
	vertices = new VertexType[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
	numVertices = 0;
	maxVertices = maxV;
	vertices = new VertexType[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
	delete[] vertices;
}
const int NULL_EDGE = 0;

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
	vertices[numVertices] = vertex;

	for (int index = 0; index < numVertices; index++)
	{
		edges[numVertices][index] = NULL_EDGE;
		edges[index][numVertices] = NULL_EDGE;
	}
	numVertices++;
}
template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
{
	int index = 0;

	while (!(vertex == vertices[index]))
		index++;
	return index;
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex,VertexType toVertex, int weight)
{
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	edges[row][col] = weight;
}

template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)
{
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	return edges[row][col];
}

template<class VertexType>
bool GraphType<VertexType>::EdgeExists(VertexType fromVertex, VertexType toVertex)
{
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);

	if (edges[row][col] > NULL_EDGE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class VertexType>
void GraphType<VertexType>::DeleteEdge(VertexType fromVertex, VertexType toVertex)
{
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);

	edges[row][col] = NULL_EDGE;
}