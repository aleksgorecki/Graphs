#include "../inc/testmanager.hh"
#include <string>
#include <iostream>
#include <chrono>
#include <fstream>
#include <ios>








void TestManager::bellmanfordTimeEfficiencyTest()
{

}


void TestManager::bellmanfordPathLogging()
{

}

void TestManager::bellmanfordCustomFileTest(std::string filename)
{
        this->customFileGraphList.fillFromFile(filename);
        this->customFileGraphMatrix.fillFromFile(filename);

        Timer timer;
        customFileGraphList.setBellmanford_startingVertex(0);
        customFileGraphMatrix.setBellmanford_startingVertex(0);
        timer.startMeasuringTime();       
        customFileGraphMatrix.bellmanford();
        customFileGraphList.bellmanford();
        timer.stopMeasuringTime();
        int bellmanfordDuration_List = timer.getMeasuredTime();

        timer.clearMeasuredTime();

        timer.startMeasuringTime();
        customFileGraphMatrix.bellmanford();
        timer.stopMeasuringTime();
        int bellmanfordDuration_Matrix = timer.getMeasuredTime();

        std::ofstream resultsFile;
        resultsFile.open("customFileResults.txt", std::ios::out);
        resultsFile << "Wyniki dzialania algorytmu bellmanaforda dla grafu wczytanego z pliku: " << std::endl << std::endl;
        resultsFile << "Reprezentacja w postaci listy sasiedztwa: " << std::endl;
        resultsFile << "czas dzialania: " << bellmanfordDuration_List << " mikrosekund" << std::endl;
        resultsFile << "Sciezki do wierzcholkow i ich koszt:" << std::endl;
        customFileGraphList.printBellmanfordPathToStream(resultsFile);

        resultsFile << std::endl << std::endl;

        resultsFile << "Reprezentacja w postaci macierzy sasiedztwa: " << std::endl;
        resultsFile << "czas dzialania: " << bellmanfordDuration_Matrix << " mikrosekund" << std::endl;
        resultsFile << "Sciezki do wierzcholkow i ich koszt:" << std::endl;
        customFileGraphMatrix.printBellmanfordPathToStream(resultsFile);
}