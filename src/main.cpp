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
	int vertexNumber = 10;
	//GraphList graf;
	GraphMatrix graf;

	graf.fillRandom(vertexNumber, density);
	//graf.fillFromFile("testInput.txt");
	
	graf.setStartingVertexForBellmanford(0);
	graf.print();
	graf.bellmanford();


	return 0;
}