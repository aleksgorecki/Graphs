#ifndef GRAPH_HH
#define GRAPH_HH

#include <fstream>

#include "linkedlist.hh"
#include "string"


class Edge;
class Graph;
class GraphList;
class GraphMatrix;


class Edge
{
    protected:
        int weight;
        int sourceVertex;
        int destinationVertex;
        LinkedList<Edge*>::Iterator edgeListPosition;
        bool operator ==(Edge e);
        bool operator !=(Edge e);
        Edge(int sV, int dV, int w) {sourceVertex = sV; destinationVertex = dV; weight = w;};
        Edge() {};
    friend class Graph;
    friend class GraphList;
    friend class GraphMatrix;
};


class Graph
{
    protected:
        LinkedList<Edge*> edgeList;
        int nVertices;
        int bellmanford_StartingVertex;
        int* bellmanford_Predecessors;
        int* bellmanford_Distance;



    public:
        virtual bool areAdjacent(int firstVertex, int secondVertex) = 0;
        virtual void insertEdge(int sourceVertex, int destinationVertex, int weight) = 0;
        virtual void allocateMemoryForDataStructure() = 0;
        virtual void print() = 0;
        virtual void fillRandom(int vertexNumber, float density) = 0;
        virtual void bellmanford() = 0;


        int vertices() {return nVertices;};
        LinkedList<Edge*> edges() {return edgeList;};
        void setBellmanford_startingVertex(int startingVertex) {bellmanford_StartingVertex = startingVertex;};
        int* getBellmanford_Predecessors() {return bellmanford_Predecessors;};
        int* getBellmanford_Distance() {return bellmanford_Distance;};
        void fillFromFile(std::string filename)
        {
            std::ifstream inputFile;
            inputFile.open(filename);
            int vertexNumber;
            int edgeNumber;
            int startingVertex;
            inputFile >> edgeNumber >> vertexNumber >> startingVertex;
            this->nVertices = vertexNumber;
            this->bellmanford_StartingVertex = startingVertex;
            allocateMemoryForDataStructure();
            int sV;
            int dV;
            int w;
            while (true)
            {
                inputFile >> sV >> dV>> w;
                insertEdge(sV, dV, w);
                if(inputFile.eof())
                {
                    break;
                }
            }
        }
        void printBellmanfordPathToStream(std::ostream& stream)
        {
            for (int i = 0; i < vertices(); i++)
            {
                stream << i << ": dystans = " << bellmanford_Distance[i] << " poprzednicy: ";
                    for (int j = i; bellmanford_Predecessors[j] != bellmanford_Predecessors[this->bellmanford_StartingVertex]; j = bellmanford_Predecessors[j])
                    {
                        stream<< bellmanford_Predecessors[j] << " ";
                    }
                stream << std::endl;
            }
        }
};





#endif