#ifndef GRAPHLIST_HH
#define GRAPHLIST_HH

#include "graph.hh"

class GraphList: public Graph
{
    private:
        LinkedList<Edge*>* adjacencyList;



    public:
        bool areAdjacent(int firstVertex, int secondVertex);
        void insertEdge(int sourceVertex, int destinationVertex, int weight);
        void fillRandom(int vertexNumber, float density);
        void print();
        void bellmanford();
        void allocateMemoryForDataStructure();
};

#endif