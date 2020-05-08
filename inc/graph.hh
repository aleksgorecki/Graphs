#ifndef GRAPH_HH
#define GRAPH_HH

#include "linkedlist.hh"

class Edge;
class Graph;



class Edge
{
    //protected:
    public:
        int weight;
        int sourceVertex;
        int destinationVertex;
        LinkedList<Edge*>::Iterator edgeListPosition;
        bool operator ==(Edge e);
        bool operator !=(Edge e);
    friend class Graph;
};


class Graph
{
    protected:
        LinkedList<Edge*> edgeList;

    public:
        virtual int endVertices(Edge e) = 0;
        virtual int opposite(int v, Edge* e) = 0;
        virtual bool areAdjacent(int firstVertex, int secondVertex) = 0;

        virtual void insertVertex(int label) = 0;
        virtual void insertEdge(int sourceVertex, int destinationVertex, int weight) = 0;

        virtual LinkedList<Edge*> incidentEdges(int v) = 0;
        virtual int* vertices() = 0;
        virtual LinkedList<Edge*> edges() = 0;

        virtual void fillRandom(int vertexNumber, float density) = 0;
};



#endif