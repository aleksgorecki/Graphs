#ifndef GRAPHMATRIX_HH
#define GRAPHMATRIX_HH

#include "graph.hh"


class GraphMatrix: private Graph
{
    private:
        Edge*** adjacencyMatrix; 
    public:
        int endVertices(Edge e) {};
        int opposite(int v, Edge* e) {};
        bool areAdjacent(int firstVertex, int secondVertex);

        void insertVertex(int label) {};
        void insertEdge(int sourceVertex, int destinationVertex, int weight);

        LinkedList<Edge*> incidentEdges(int v) {};
        int vertices();
        LinkedList<Edge*> edges() {};

        void fillRandom(int vertexNumber, float density);

        GraphMatrix() {nVertices = 0;};
        void bellmanford();
};


#endif