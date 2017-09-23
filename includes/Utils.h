#ifndef UTILS_H
#define UTILS_H

#include <limits>
#include <vector>


#include "Tour.h"
class Tour;
#include "Population.h"

using std::numeric_limits;
using std::vector;

const int RES{10000};

double maxFitness(vector<Tour>&);

#endif