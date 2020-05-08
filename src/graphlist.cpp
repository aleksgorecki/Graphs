#include "../inc/graphlist.hh"

#include <random>



int GraphList::vertices()
{
    return this->nVertices;
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
    this->adjacencyList = new LinkedList<Edge*>[vertices()];
    int edgesToCreate = (density * vertexNumber * (vertexNumber - 1))/2;
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
        } while (sV == dV || areAdjacent(sV, dV));
        weight = rand() % maxWeight + 1;
        insertEdge(sV, dV, weight);
        insertEdge(dV, sV, weight);
    }


    for (int i = 0; i < vertices(); i++)
    {
        std::cout << i << " - ";
        for (LinkedList<Edge*>::Iterator iter = adjacencyList[i].begin(); iter != adjacencyList[i].end(); ++iter)
        {
            std::cout << iter.getData()->destinationVertex << "->";
        }
        std::cout << std::endl;
    }
    

}

void GraphList::bellmanford()
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

    for (int i = 0; i < vertices(); i++)
    {
        std::cout << predecessor[i] << "  --  " << distance[i] << std::endl;
    }
    delete[] distance;
    delete[] predecessor;
}