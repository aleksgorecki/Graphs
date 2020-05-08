//placeholder

#include <iostream>
#include <random>
#include <ctime>

#include "../inc/linkedlist.hh"
#include "../inc/graph.hh"
#include "../inc/graphlist.hh"




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
	int vertexNumber = 5;
	GraphList graf;

	graf.fillRandom(vertexNumber, density);
	graf.bellmanford();


	return 0;
}