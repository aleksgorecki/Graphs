//placeholder

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

#include "../inc/linkedlist.hh"
#include "../inc/graph.hh"
#include "../inc/graphlist.hh"
#include "../inc/graphmatrix.hh"
#include "../inc/testmanager.hh"




//funkcja pomocnicza na czas testow:
template <typename T>
void Log(T data)
{
	std::cout << data << std::endl;
}




int main()
{



	srand(time(0));	
	float density = 0.25;
	int vertexNumber = 10;
	GraphList Lgraph;
	GraphMatrix Mgraph;

	TestManager manager;
	Lgraph.fillRandom(vertexNumber, density);
	Lgraph.print();
	Lgraph.setBellmanford_startingVertex(0);
	Lgraph.bellmanford();
	Lgraph.getBellmanford_Predecessors();
	manager.bellmanfordCustomFileTest("testInput.txt");

	return 0;
}