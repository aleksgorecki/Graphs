#ifndef GRAPHMATRIX_HH
#define GRAPHMATRIX_HH

#include "graph.hh"


class GraphMatrix: private Graph
{
    private:
        Edge*** adjacencyMatrix; 
    public:

        bool areAdjacent(int firstVertex, int secondVertex);

        void insertEdge(int sourceVertex, int destinationVertex, int weight);

        int vertices();
        LinkedList<Edge*> edges();

        void fillRandom(int vertexNumber, float density);

        void allocateMemoryForDataStructure();
        void bellmanford();
        void print();
        void fillFromFile(char* filename);
        void setStartingVertexForBellmanford(int startingVertex);

};


#endif