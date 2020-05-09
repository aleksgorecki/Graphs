#include "../inc/graphlist.hh"

#include <random>
#include <ios>
#include <fstream>
#include <chrono>

void GraphList::setStartingVertexForBellmanford(int startingVertex)
{
    this->startingVertexForBellmanford = startingVertex;
}

int GraphList::vertices()
{
    return this->nVertices;
}

LinkedList<Edge*> GraphList::edges()
{  
    return edgeList;
}

void GraphList::allocateMemoryForDataStructure()
{
    this->adjacencyList = new LinkedList<Edge*>[vertices()];
}

bool GraphList::areAdjacent(int v1, int v2)
{
    if(adjacencyList[v1].isEmpty())
    {
        return false;
    }
    for (LinkedList<Edge*>::Iterator iter = adjacencyList[v1].begin(); iter != adjacencyList[v1].end(); ++iter)
    {
        if (iter.getData()->destinationVertex == v2)
        {
            return true;
        }
    }
    return false;
}

void GraphList::insertEdge(int sV, int dV, int w)
{
    Edge* newEdge = new Edge(sV, dV, w);
    newEdge->edgeListPosition = this->edgeList.insertBack(newEdge);
    adjacencyList[sV].insertBack(newEdge);
}

void GraphList::fillRandom(int vertexNumber, float density)
{
    int maxWeight = 100;
    this->nVertices = vertexNumber;
    allocateMemoryForDataStructure();
    int edgesToCreate = (density * vertexNumber * (vertexNumber - 1));
    LinkedList<int> alreadyConnectedVertices;
    int sV = 0;
    int dV;
    int weight;
    for (int i = 1; i < vertexNumber; i++)
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
        } while (sV == dV);
        weight = rand() % maxWeight + 1;
        insertEdge(sV, dV, weight);
        insertEdge(dV, sV, weight);
    }
}

void GraphList::bellmanford()
{
    int startingVertex = startingVertexForBellmanford;

    int infinity = 1000000;
    int* distance = new int[vertices()];
    int* predecessor = new int[vertices()];

    auto bellmanfordStart = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < vertices(); i++)
    {
        distance[i] = infinity;
        predecessor[i] = -99;
    }
    distance[startingVertex] = 0;
    for (int i = 0; i < vertices() - 1; i++)
    {
        for(int j = 0; j < vertices(); j++)
        {
            for (LinkedList<Edge*>::Iterator iter = adjacencyList[j].begin(); iter != adjacencyList[j].end(); ++iter)
            {
                if (distance[j] + iter.getData()->weight < distance[iter.getData()->destinationVertex])
                {
                    distance[iter.getData()->destinationVertex] = distance[j] + iter.getData()->weight;
                    predecessor[iter.getData()->destinationVertex] = j;
                }
            }
        }
    }
    auto bellmanfordEnd = std::chrono::high_resolution_clock::now();
    int bellmanfordDuration = std::chrono::duration_cast<std::chrono::microseconds>(bellmanfordEnd - bellmanfordStart).count();
    std::cout << bellmanfordDuration << std::endl;

    for (int i = 0; i < vertices(); i++)
    {
        std::cout << i << ": dystans = " << distance[i] << " poprzednicy: ";
        for (int j = i; predecessor[j] != -99; j = predecessor[j])
        {
            std::cout << predecessor[j] << " ";
        }
        std::cout << std::endl;
    }
    delete[] distance;
    delete[] predecessor;
}

void GraphList::print()
{
    for(int i = 0; i < vertices(); i++)
    {
        std::cout << i;
        for (LinkedList<Edge*>::Iterator iter = adjacencyList[i].begin(); iter != adjacencyList[i].end(); ++iter)
        {
            std::cout << "<-->" << iter.getData()->destinationVertex;
        } 
        std::cout << std::endl;
    }
}

void GraphList::fillFromFile(char* filename)
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