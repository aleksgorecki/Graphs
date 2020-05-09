#ifndef GRAPHMATRIX_HH
#define GRAPHMATRIX_HH

#include "graph.hh"


class GraphMatrix: public Graph
{
    private:
        Edge*** adjacencyMatrix; 



    public:
        bool areAdjacent(int firstVertex, int secondVertex);
        void insertEdge(int sourceVertex, int destinationVertex, int weight);
        void fillRandom(int vertexNumber, float density);
        void allocateMemoryForDataStructure();
        void bellmanford();
        void print();
};


#endif