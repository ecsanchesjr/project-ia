#ifndef UTILS_H
#define UTILS_H

#include <limits>
#include <vector>
#include "Population.hpp"


using std::numeric_limits;
using std::vector;

const int RES = 10000; // Number to improve the visualization of fitness values.

// Percentages values.
static int MUT_PERCENTAGE;
static int ELITISM_TOTAL;

// Support values.
static int CROSS_METHOD;

static vector<City> firstPoint;

bool compareDouble(const double,const double);

double maxFitness(vector<Tour>&);

double distance(City&, City&);

bool contains(vector<City>&, City&);

City eraseAndReturn(vector<City>&, const int);

int findLowerDistance(vector<City>, City);

double convertRanges(const int, const double);

#endif