#ifndef GRAPHMATRIX_HH
#define GRAPHMATRIX_HH

#include "graph.hh"


class GraphMatrix: private Graph
{
    private:
        Edge*** adjacencyMatrix; 
    public:
        LinkedList<Vertex*> endVertices(Edge e);
        Vertex* opposite(Vertex* v, Edge* e);
        bool areAdjacent(Vertex* firstVertex, Vertex* secondVertex);
        void replace(Vertex* v, int newLabel);
        void replace(Edge* e, int newWeight);

        void insertVertex(int label);
        void insertEdge(Vertex* sourceVertex, Vertex* destinationVertex, int weight);
        void removeVertex(Vertex* v) {};
        void removeEdge(Edge* e) {};

        LinkedList<Edge*> incidentEdges(Vertex v);
        LinkedList<Vertex*> vertices();
        LinkedList<Edge*> edges();

        void fillRandom(int vertexNumber, float density);
};


#endif