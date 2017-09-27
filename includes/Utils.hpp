#ifndef UTILS_H
#define UTILS_H

#include <limits>
#include <vector>
#include "Population.hpp"


using std::numeric_limits;
using std::vector;

//const int RES{10000};

static vector<City> firstPoint;

double maxFitness(vector<Tour>&);

double distance(City&, City&);

bool contains(vector<City>&, City&);

City eraseAndReturn(vector<City>&, const int);

int findLowerDistance(vector<City>, City);

#endif