#ifndef TESTMANAGER_HH
#define TESTMANAGER_HH

#include "graph.hh"
#include "graphlist.hh"
#include "graphmatrix.hh"


class TestManager
{
    private:
        GraphList*** defaultGraphListSet;
        GraphMatrix*** defaultGraphMatrixSet;
    public:
        void bellmanfordTimeEfficiencyTest(bool useCustomFile);
        void bellmanfordResultsLogging(bool useCustomFile);
};




#endif