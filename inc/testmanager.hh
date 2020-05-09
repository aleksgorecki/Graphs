#ifndef TESTMANAGER_HH
#define TESTMANAGER_HH

#include "graph.hh"
#include "graphlist.hh"
#include "graphmatrix.hh"
#include <string>
#include <chrono>


class Timer
{
    private:
        std::chrono::high_resolution_clock::time_point startPoint;
        std::chrono::high_resolution_clock::time_point endPoint;


        
    public:
        void startMeasuringTime() {startPoint = std::chrono::high_resolution_clock::now();};
        void stopMeasuringTime() {endPoint = std::chrono::high_resolution_clock::now();};
        void clearMeasuredTime() {startPoint = endPoint;};
        int getMeasuredTime() {return std::chrono::duration_cast<std::chrono::microseconds>(endPoint - startPoint).count();};
};



class TestManager
{
    private:
        GraphList*** defaultGraphListSet;
        GraphMatrix*** defaultGraphMatrixSet;
        GraphList customFileGraphList;
        GraphMatrix customFileGraphMatrix;



    public:
        void bellmanfordTimeEfficiencyTest();
        void bellmanfordPathLogging();
        void bellmanfordCustomFileTest(std::string filename);
};





#endif