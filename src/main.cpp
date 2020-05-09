//placeholder

#include <iostream>
#include <random>
#include <ctime>

#include "../inc/linkedlist.hh"
#include "../inc/graph.hh"
#include "../inc/graphlist.hh"
#include "../inc/graphmatrix.hh"




//funkcja pomocnicza na czas testow:
template <typename T>
void Log(T data)
{
	std::cout << data << std::endl;
}




int main()
{

	srand(time(0));	
	float density = 1;
	int vertexNumber = 100;
	GraphList Lgraph;
	GraphMatrix Mgraph;

	Lgraph.fillRandom(vertexNumber, density);
	Mgraph.fillRandom(vertexNumber, density);
	
	//Mgraph.fillFromFile("testInput.txt");
	
	Mgraph.setStartingVertexForBellmanford(0);
	Lgraph.setStartingVertexForBellmanford(0);
	Mgraph.bellmanford();
	BellmanfordTestResults LResults = Lgraph.bellmanford();
	BellmanfordTestResults MResults = Mgraph.bellmanford();
	std::cout << "list: " <<LResults.testDuration << std::endl;
	std::cout << "matrix: " << MResults.testDuration<< std::endl;


	return 0;
}