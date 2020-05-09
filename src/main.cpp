#include <iostream>
#include <random>
#include <ctime>

#include "../inc/linkedlist.hh"
#include "../inc/graph.hh"
#include "../inc/graphlist.hh"
#include "../inc/graphmatrix.hh"
#include "../inc/testmanager.hh"

int main()
{
	srand(time(0));
	int choice;
	std::cout << "Prosty program do zarzadzania testami" << std::endl << std::endl;
	std::cout << "1 - test efektywnosci czasowej algorytmu Bellmana-Forda w zaleznosci od sposobu reprezentacji grafu" << std::endl;
	std::cout << "2 - Wczytanie grafu z pliku, oraz wypisanie sciezki algorytmu Bellmana-Forda dla tego grafu do pliku wynikowego o nazwie customFileResults.txt" << std::endl;
	std::cout << "3 - Wyjscie" << std::endl;
	std::cout << std::endl;
	std::cout << "Wybor > ";
	std::cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3)
	{
		std::cout << "Podano niewlasciwa liczbe" << std::endl;
		std::cout << "Wybor > ";
		std::cin >> choice;
	}
	TestManager manager;
	manager.bellmanfordTimeEfficiencyTest();
	return 0;
}