#ifndef GRAPHLIST_HH
#define GRAPHLIST_HH


#include "graph.hh"





class GraphList: private Graph
{
    private:
        LinkedList<Edge*>* adjacencyList;
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

        GraphList() {nVertices = 0; edgeList; adjacencyList;};
        void bellmanford();
};


#endif