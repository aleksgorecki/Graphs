#include "../inc/graphlist.hh"

#include <random>






LinkedList<Vertex*> GraphList::endVertices(Edge e)
{
    LinkedList<Vertex*> vertices;
    vertices.insertFront(e.destinationVertex);
    vertices.insertFront(e.sourceVertex);
    return vertices;
}

Vertex* GraphList::opposite(Vertex* v, Edge* e)
{
    return e->destinationVertex;
}

bool GraphList::areAdjacent(Vertex* firstVertex, Vertex* secondVertex)
{
    if (firstVertex->AdjacencyList.isEmpty())
    {
        return false;
    }
    LinkedList<Edge*>::Iterator iter;
    for (iter = firstVertex->AdjacencyList.begin(); iter != firstVertex->AdjacencyList.end(); ++iter)
    {
        if ( iter.getData()->destinationVertex == secondVertex)
        {
            return true;
        }
    }
    /*
    for (iter = secondVertex->AdjacencyList.begin(); iter != secondVertex->AdjacencyList.end(); ++iter)
    {
        if ( *iter.getData()->destinationVertex == *firstVertex)
        {
            return true;
        }
    } 
    */
    return false;
}

void GraphList::replace(Vertex* v, int newLabel)
{
    v->label = newLabel;
}

void GraphList::replace(Edge* e, int newWeight)
{
    e->weight = newWeight;
}

void GraphList::insertVertex(int newLabel)
{
    Vertex* newVertex = new Vertex;
    newVertex->label = newLabel;
    newVertex->vertexListPosition = vertexList.insertFront(newVertex);
}

void GraphList::insertEdge(Vertex* sourceVertex, Vertex* destinationVertex, int weight)
{
    Edge* newEdge = new Edge;
    newEdge->weight = weight;
    newEdge->sourceVertex = sourceVertex;
    newEdge->destinationVertex = destinationVertex;
    sourceVertex->AdjacencyList.insertBack(newEdge);
    newEdge->edgeListPosition = edgeList.insertFront(newEdge);  
}


/*

void GraphList::removeEdge(Edge e)
{
    for (LinkedList<Edge*>::Iterator iter = e.sourceVertex->AdjacencyList.end(); *iter.getData() != e; --iter)
    {
        e.sourceVertex->AdjacencyList.removeAtPosition(iter);
    }
    edgeList.removeAtPosition(e.edgeListPosition);
}

void GraphList::removeVertex(Vertex v)
{
    for (LinkedList<Vertex>::Iterator iter = vertexList.begin(); iter != vertexList.end(); ++iter)
    {
        std::cout << "test " << iter.getData().label << std::endl;
        for (LinkedList<Edge*>::Iterator iter2 = iter.getData().AdjacencyList.begin(); iter2 != iter.getData().AdjacencyList.end(); ++iter2)
        {
            std::cout << "test2" << std::endl;
            if ( *iter.getData()->sourceVertex == v ||  *iter.getData()->destinationVertex == v)
            {
               // removeEdge(*iter.getData());
               
            }
        }
    }
    vertexList.removeAtPosition(v.vertexListPosition);
}

*/



LinkedList<Edge*> GraphList::incidentEdges(Vertex v)
{
    return v.AdjacencyList;
}

LinkedList<Vertex*> GraphList::vertices()
{
    return vertexList;
}

LinkedList<Edge*> GraphList::edges()
{
    return edgeList;
}

void GraphList::fillRandom(int vertexNumber, float density)
{
    int maxWeight = 100;

    int edgesToCreate = density * (vertexNumber * (vertexNumber - 1));
    Vertex** createdVertices = new Vertex*[vertexNumber];
    insertVertex(0);
    createdVertices[0] = vertexList.begin().getData();
    for (int i = 1; i < vertexNumber; i++)
    {
        insertVertex(i);
        createdVertices[i] = vertexList.begin().getData();
        insertEdge(createdVertices[i],createdVertices[i-1], rand() % maxWeight + 1 );
    }
    Vertex* sourceVertex;
    Vertex* destinationVertex;
    int remainingEdges = edgesToCreate - edges().getSize();
    for ( int i = 0; i < remainingEdges; i++)
    {
        do
        {
            sourceVertex = createdVertices[rand() % vertexNumber];
            destinationVertex = createdVertices[rand() % vertexNumber];
        } while (sourceVertex == destinationVertex || areAdjacent(sourceVertex, destinationVertex));
        insertEdge(sourceVertex, destinationVertex, rand() % maxWeight + 1);
    }
    delete[] createdVertices;
}

void GraphList::bellmanford()
{
    Vertex* startingVertex = vertices().begin().getData();
    bool visited = false;
    int infinity = 1000000;
    int* distance = new int[vertices().getSize()];
    Vertex** predecessor = new Vertex*[vertices().getSize()];
    for (int i = 0; i < vertices().getSize(); i++)
    {
        distance[i] = infinity;
        predecessor[i] = NULL;
    }
    distance[startingVertex->label] = 0;
    for (int i = 0; i < vertices().getSize(); i++)
    {

    }
    for (int i = 0; i < vertices().getSize(); i++)
    {
       std::cout << predecessor[i]->label << "  --  " << distance[i] << std::endl;
    }
    
    std::cout << vertices().begin().getData()->label << std::endl;
    delete[] distance;
    delete[] predecessor;
}


/*
void GraphList::bellmanford()
{
    Vertex* startingVertex = vertices().begin().getData();
    int infinity = 1000000;
    int* distance = new int[vertices().getSize()];
    Vertex** predecessor = new Vertex*[vertices().getSize()];
    for (int i = 0; i < vertices().getSize(); i++)
    {
        distance[i] = infinity;
        predecessor[i] = NULL;
    }
    distance[startingVertex->label] = 0;
    for (int i = 0; i < vertices().getSize(); i++)
    {
        for (LinkedList<Edge*>::Iterator edgeIter = edges().begin(); edgeIter != edges().end(); ++edgeIter)
        {
            if (distance[edgeIter.getData()->sourceVertex->label] + edgeIter.getData()->weight < distance[edgeIter.getData()->destinationVertex->label])
            {
                distance[edgeIter.getData()->destinationVertex->label] = distance[edgeIter.getData()->sourceVertex->label] + edgeIter.getData()->weight;
                predecessor[edgeIter.getData()->destinationVertex->label] = edgeIter.getData()->sourceVertex;
                std::cout << "d" << edgeIter.getData()->destinationVertex->label << std::endl;
                std::cout << "p" << edgeIter.getData()->sourceVertex->label << std::endl;
            }
        }
    }
    for (int i = 0; i < vertices().getSize(); i++)
    {
       // std::cout << predecessor[i]->label << "  --  " << distance[i] << std::endl;
    }
    delete[] distance;
    delete[] predecessor;
}
*/