#ifndef GRAPHLIST_HH
#define GRAPHLIST_HH


#include "graph.hh"





class GraphList: private Graph
{
    private:
        LinkedList<Edge*>* adjacencyList;
    public:
        bool areAdjacent(int firstVertex, int secondVertex);

        void insertEdge(int sourceVertex, int destinationVertex, int weight);

        int vertices();
        LinkedList<Edge*> edges();

        void fillRandom(int vertexNumber, float density);

        void print();
        void bellmanford();
        void fillFromFile(char* filename);
        void allocateMemoryForDataStructure();
        void setStartingVertexForBellmanford(int startingVertex);
};


#endif