#ifndef TESTMANAGER_HH
#define TESTMANAGER_HH

#include "graph.hh"
#include "graphlist.hh"
#include "graphmatrix.hh"
#include <string>
#include <chrono>

class TestManager
{
    private:
        float densities[4] = {0.25, 0.5, 0.75, 1};
        int nVertices[5] = {10, 25, 50, 100, 150};



    public:
        void bellmanfordTimeEfficiencyTest();
        void newbellmanfordTimeEfficiencyTest();
        void bellmanfordCustomFilePath(std::string filename);

        void prepareRandomGraphSets();
};

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


#endif