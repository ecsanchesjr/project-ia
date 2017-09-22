#ifndef POPULATION_H
#define POPULATION_H

#include <vector>

#include "Tour.h"
#include "Map.h"

using std::vector;

class Population{

public:
    Population();
    Population(Map&, const int);

    vector<Tour>& getPop();

private:
    vector<Tour> pop;
    Tour elitism();
};

#endif