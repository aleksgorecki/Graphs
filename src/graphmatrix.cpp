#include "../inc/graphmatrix.hh"
#include "../inc/graphmatrix.hh"



int GraphMatrix::vertices()
{
    return nVertices;
}

bool GraphMatrix::areAdjacent(int v1, int v2)
{
    if ((adjacencyMatrix[v1][v2] != NULL) && (adjacencyMatrix[v2][v1] != NULL))
    {
        return true;
    }
    return false;
}

void GraphMatrix::insertEdge(int sV, int dV, int w)
{
    Edge* newEdge = new Edge(sV, dV, w);
    newEdge->edgeListPosition = this->edgeList.insertBack(newEdge);
    this->adjacencyMatrix[sV][dV] = newEdge;
}

void GraphMatrix::fillRandom(int vertexNumber, float density)
{
    int maxWeight = 100;
    this->nVertices = vertexNumber;
    this->adjacencyMatrix = new Edge**[vertices()];
    for (int i = 0; i < vertices(); i++)
    {
        this->adjacencyMatrix[i] = new Edge*[vertices()];
    }
    int edgesToCreate = (density * vertexNumber * (vertexNumber - 1))/2;
    LinkedList<int> alreadyConnectedVertices;
    int sV = 0;
    int dV;
    int weight;
    for (int i = 0; i < vertices(); i++)
    {
        for (int j = 0; j < vertices(); j++)
        {
            adjacencyMatrix[i][j] = NULL;
        }
    }
    for (int i = 0; i < vertices(); i++)
    {
        alreadyConnectedVertices.insertFront(sV);
        do
        {
            dV = rand() % vertexNumber;
        } while (sV == dV || areAdjacent(sV, dV) || areAdjacent(dV, sV) || alreadyConnectedVertices.contains(dV));
        weight = rand() % maxWeight + 1;
        insertEdge(sV, dV, weight);
        insertEdge(dV, sV, weight);
        sV = dV;
    }
    int remainingEdges = edgesToCreate - this->edgeList.getSize();
    for (int i = 0; i < remainingEdges; i++)
    {
        sV = rand() % vertexNumber;
        do
        {
            dV = rand() % vertexNumber;
        } while (sV == dV || areAdjacent(sV, dV));
        weight = rand() % maxWeight + 1;
        insertEdge(sV, dV, weight);
        insertEdge(dV, sV, weight);
    }
}

void GraphMatrix::bellmanford()
{
    int startingVertex = 4;

    int infinity = 1000000;
    int* distance = new int[vertices()];
    int* predecessor = new int[vertices()];
    for (int i = 0; i < vertices(); i++)
    {
        distance[i] = infinity;
        predecessor[i] = -99;
    }
    distance[startingVertex] = 0;

    for (int i = 0; i < vertices(); i++)
    {


        for(int j = 0; j < vertices(); j++)
        {
            for (int k = 0; k < vertices(); k++)
            {

            }
        }

        
    }

    for (int i = 0; i < vertices(); i++)
    {
        std::cout << predecessor[i] << "  --  " << distance[i] << std::endl;
    }
    delete[] distance;
    delete[] predecessor;
}