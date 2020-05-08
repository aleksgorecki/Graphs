#ifndef GRAPH_HH
#define GRAPH_HH

#include "linkedlist.hh"

class Edge;
class Graph;

class Vertex
{
    //protected:
    public:
        int label;
        LinkedList<Edge*> AdjacencyList;
        LinkedList<Vertex*>::Iterator vertexListPosition;
        bool operator ==(Vertex v);
        bool operator !=(Vertex v);
    friend class Edge;
    friend class Graph;
};

std::ostream& operator << (std::ostream& out, Vertex v);





class Edge
{
    //protected:
    public:
        int weight;
        Vertex* sourceVertex;
        Vertex* destinationVertex;
        LinkedList<Edge*>::Iterator edgeListPosition;
        bool operator ==(Edge e);
        bool operator !=(Edge e);
    friend class Graph;
};


class Graph
{
    protected:
        LinkedList<Vertex*> vertexList;
        LinkedList<Edge*> edgeList;

    public:
        virtual LinkedList<Vertex*> endVertices(Edge e) = 0;
        virtual Vertex* opposite(Vertex* v, Edge* e) = 0;
        virtual bool areAdjacent(Vertex* firstVertex, Vertex* secondVertex) = 0;
        virtual void replace(Vertex* v, int newLabel) = 0;
        virtual void replace(Edge* e, int newWeight) = 0;

        virtual void insertVertex(int label) = 0;
        virtual void insertEdge(Vertex* sourceVertex, Vertex* destinationVertex, int weight) = 0;
        virtual void removeVertex(Vertex* v) = 0;
        virtual void removeEdge(Edge* e) = 0;

        virtual LinkedList<Edge*> incidentEdges(Vertex v) = 0;
        virtual LinkedList<Vertex*> vertices() = 0;
        virtual LinkedList<Edge*> edges() = 0;

        virtual void fillRandom(int vertexNumber, float density) = 0;
};



#endif