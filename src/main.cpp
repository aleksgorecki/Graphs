//placeholder

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

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

    auto bellmanfordStart = std::chrono::high_resolution_clock::now();
	auto bellmanfordEnd = std::chrono::high_resolution_clock::now();
    int bellmanfordDuration = std::chrono::duration_cast<std::chrono::microseconds>(bellmanfordEnd - bellmanfordStart).count();

	srand(time(0));	
	float density = 0.25;
	int vertexNumber = 10;
	GraphList Lgraph;
	GraphMatrix Mgraph;

	Lgraph.fillRandom(vertexNumber, density);
	//Mgraph.fillRandom(vertexNumber, density);
	
	//Mgraph.fillFromFile("testInput.txt");
	
	Lgraph.print();
	Mgraph.setStartingVertexForBellmanford(2);
	Lgraph.setStartingVertexForBellmanford(0);
	Lgraph.bellmanford();
	//BellmanfordTestResults LResults = Lgraph.bellmanford();
	//BellmanfordTestResults MResults = Mgraph.bellmanford();
	//std::cout << "list: " <<LResults.testDuration << std::endl;
	//std::cout << "matrix: " << MResults.testDuration<< std::endl;


	return 0;
}