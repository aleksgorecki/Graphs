#include "../inc/graphmatrix.hh"
#include "../inc/graphmatrix.hh"

#include <ios>
#include <fstream>

void GraphMatrix::setStartingVertexForBellmanford(int startingVertex)
{
    this->startingVertexForBellmanford = startingVertex;
}


int GraphMatrix::vertices()
{
    return nVertices;
}

LinkedList<Edge*> GraphMatrix::edges()
{  
    return edgeList;
}

void GraphMatrix::allocateMemoryForDataStructure()
{
    this->adjacencyMatrix = new Edge**[vertices()];
    for (int i = 0; i < vertices(); i++)
    {
        this->adjacencyMatrix[i] = new Edge*[vertices()];
    }
    for (int i = 0; i < vertices(); i++)
    {
        for (int j = 0; j < vertices(); j++)
        {
            adjacencyMatrix[i][j] = NULL;
        }
    }
}

bool GraphMatrix::areAdjacent(int v1, int v2)
{
    if ((adjacencyMatrix[v1][v2] != NULL))
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
    allocateMemoryForDataStructure();
    int edgesToCreate = (density * vertexNumber * (vertexNumber - 1))/2;
    LinkedList<int> alreadyConnectedVertices;
    int sV = 0;
    int dV;
    int weight;

    for (int i = 1; i < vertices(); i++)
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
    int startingVertex = startingVertexForBellmanford;

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
                if (adjacencyMatrix[j][k] != NULL)
                {
                    if (distance[j] + adjacencyMatrix[j][k]->weight < distance[k])
                    {
                        distance[k] = distance[j] + adjacencyMatrix[j][k]->weight;
                        predecessor[k] = j;
                    }
                }

            }
        }


    }


    for (int i = 0; i < vertices(); i++)
    {
        std::cout << i << ": dystans = " << distance[i] << " poprzednicy: ";
            for (int j = i; j != predecessor[startingVertex]; j = predecessor[j])
            {
                std::cout << predecessor[j] << " ";
            }
        std::cout << std::endl;
    }
    delete[] distance;
    delete[] predecessor;
}

void GraphMatrix::print()
{
    for (int i = 0; i < vertices(); i++)
    {
        for (int j = 0; j < vertices(); j++)
        {
            if (adjacencyMatrix[i][j] != NULL)
            {
                std::cout << 1;
            }
            else
            {
                std::cout << 0;
            }
        }
        std::cout << std::endl;
    }
}

void GraphMatrix::fillFromFile(char* filename)
{
    std::ifstream inputFile;
    inputFile.open(filename);
    int vertexNumber;
    int edgeNumber;
    int startingVertex;
    inputFile >> edgeNumber >> vertexNumber >> startingVertex;
    this->nVertices = vertexNumber;
    this->startingVertexForBellmanford = startingVertex;
    allocateMemoryForDataStructure();

    int sV;
    int dV;
    int w;
    while (true)
    {
        inputFile >> sV >> dV>> w;
        insertEdge(sV, dV, w);
        if(inputFile.eof())
        {
            break;
        }
    }

}