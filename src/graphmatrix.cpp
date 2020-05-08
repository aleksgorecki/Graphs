#include "../inc/graphmatrix.hh"

LinkedList<Vertex*> GraphMatrix::endVertices(Edge e)
{
    LinkedList<Vertex*> vertices;
    vertices.insertFront(e.destinationVertex);
    vertices.insertFront(e.sourceVertex);
    return vertices;
}

Vertex* GraphMatrix::opposite(Vertex* v, Edge* e)
{
    return e->destinationVertex;
}

bool GraphMatrix::areAdjacent(Vertex* firstVertex, Vertex* secondVertex)
{
    if (adjacencyMatrix[firstVertex->label][secondVertex->label] != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GraphMatrix::replace(Vertex* v, int newLabel)
{
    v->label = newLabel;
}

void GraphMatrix::replace(Edge* e, int newWeight)
{
    e->weight = newWeight;
}

void GraphMatrix::insertVertex(int label)
{
    Vertex* newVertex = new Vertex;
    newVertex->label = label;
    vertexList.insertBack(newVertex);
    newVertex->vertexListPosition = vertexList.end();
    Edge* newAdjacencyMatrix[vertexList.getSize()][vertexList.getSize()];
    for(int i = 0; i < vertexList.getSize() - 1; i++)
    {
        for(int j = 0; j < vertexList.getSize() - 1; j++)
        {
            newAdjacencyMatrix[i][j] = adjacencyMatrix[i][j];
        }
    }
    for(int i = 0; i < vertexList.getSize(); i++)
    {
        newAdjacencyMatrix[i][label] = NULL;
    }
    for(int i = 0; i < vertexList.getSize(); i++)
    {
        newAdjacencyMatrix[label][i] = NULL;
    }
    //adjacencyMatrix = newAdjacencyMatrix;
}

void GraphMatrix::insertEdge(Vertex* sourceVertex, Vertex* destinationVertex, int weight)
{
    Edge* newEdge = new Edge;
    newEdge->weight = weight;
    newEdge->sourceVertex = sourceVertex;
    newEdge->destinationVertex = destinationVertex;
    newEdge->edgeListPosition = edgeList.insertBack(newEdge);
    adjacencyMatrix[sourceVertex->label][destinationVertex->label] = newEdge;
}


LinkedList<Edge*> GraphMatrix::incidentEdges(Vertex v)
{
    LinkedList<Edge*> returnList;
    for (int i = 0; i < vertexList.getSize(); i++)
    {
        if (adjacencyMatrix[v.label][i] != NULL)
        {
            returnList.insertBack(adjacencyMatrix[v.label][i]);
        }
    }
    return returnList;
}

LinkedList<Vertex*> GraphMatrix::vertices()
{
    return vertexList;
}

LinkedList<Edge*> GraphMatrix::edges()
{
    return edgeList;
}

void GraphMatrix::fillRandom(int vertexNumber, float density)
{

}