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


std::ostream& operator << (std::ostream& out, Vertex v)
{

    out << v.label;
    return out;
}

int main()
{

	srand(time(0));	

	Vertex v;
	GraphList graf;

	int vertexNumber = 5;
	float density = 0.5;

	graf.fillRandom(vertexNumber, density);
	graf.bellmanford();


	return 0;
}