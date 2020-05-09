#include <chrono>
#include <fstream>
#include <ios>

#include "../inc/testmanager.hh"

void TestManager::bellmanfordTimeEfficiencyTest()
{
    GraphList testingGraphList[100];
    GraphMatrix testingGraphMatrix[100];   
    Timer timer;
    std::fstream resultsFile;

    resultsFile.open("timeEfficiencyTestResults.txt", std::ios::out);
    resultsFile << "Wyniki testu efektywnosci algorytmu bellmanaforda w zaleznosci od reprezentacji grafu. Wyniki podawane sa w mikrosekundach, i sa usrednione dla zestawu 100 losowych grafow dla danej gestosci i ilosci wierzcholkow." << std::endl << std::endl;
    resultsFile << "Reprezentacja w postaci listy sasiedztwa: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
        resultsFile << "gestosc grafu: " << densities[i] << std::endl;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                testingGraphList[k].fillRandom(nVertices[j], densities[i]);
                testingGraphList[k].setBellmanford_startingVertex(0);
            }
            resultsFile << " ilosc wierzcholkow: " << nVertices[j] << " ";
            timer.startMeasuringTime();
            for (int k = 0; k < 100; k++)
            {
                testingGraphList[k].bellmanford();
            }
            timer.stopMeasuringTime();
            resultsFile << "czas: " << timer.getMeasuredTime()/100 << std::endl;
            timer.clearMeasuredTime();
        }
    }
    resultsFile << std::endl << "Reprezentacja w postaci macierzy sasiedztwa: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
        resultsFile << "gestosc grafu: " << densities[i] << std::endl;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                testingGraphMatrix[k].fillRandom(nVertices[j], densities[i]);
                testingGraphMatrix[k].setBellmanford_startingVertex(0);
            }
            resultsFile << " ilosc wierzcholkow: " << nVertices[j] << " ";
            timer.startMeasuringTime();
            for (int k = 0; k < 100; k++)
            {
                testingGraphMatrix[k].bellmanford();
            }
            timer.stopMeasuringTime();
            resultsFile << "czas: " << timer.getMeasuredTime()/100 << std::endl;
            timer.clearMeasuredTime();
        }
    }
}

void TestManager::bellmanfordCustomFilePath(std::string filename)
{
    GraphList customFileGraphList;
    GraphMatrix customFileGraphMatrix;
    customFileGraphList.fillFromFile(filename);
    customFileGraphMatrix.fillFromFile(filename);
    Timer timer;
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
    resultsFile << "Wyniki dzialania algorytmu bellmanaforda dla grafu wczytanego z pliku: "  << std::endl << std::endl;
    resultsFile << "Reprezentacja w postaci listy sasiedztwa: " << std::endl;
    resultsFile << "czas dzialania: " << bellmanfordDuration_List << " mikrosekund" << std::endl;
    resultsFile << "Sciezki do wierzcholkow i pokonany dystans:" << std::endl;
    customFileGraphList.printBellmanfordPathToStream(resultsFile);
    resultsFile << std::endl << std::endl;
    resultsFile << "Reprezentacja w postaci macierzy sasiedztwa: " << std::endl;
    resultsFile << "czas dzialania: " << bellmanfordDuration_Matrix << " mikrosekund" << std::endl;
    resultsFile << "Sciezki do wierzcholkow i pokonany dystans:" << std::endl;
    customFileGraphMatrix.printBellmanfordPathToStream(resultsFile);
}