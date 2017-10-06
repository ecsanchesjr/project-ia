#ifndef UTILS_H
#define UTILS_H

#include <limits>
#include <vector>
#include "Population.hpp"


using std::numeric_limits;
using std::vector;

/*-------------------------
    Support values.
--------------------------*/
static int CROSS_METHOD;
static int MUT_PERCENTAGE;
static int ELITISM_TOTAL;

const int RES = 10000; // Number to improve the visualization of fitness values.
static vector<City> firstPoint; // Save the cities to random-first generation
static vector<Tour> elitismTours; // Save the best Tours to Elitism

/*----------------------
    Utilities Functions
------------------------*/

bool compareDouble(const double,const double);

double maxFitness(vector<Tour>&);

double distance(City&, City&);

bool contains(vector<City>&, City&);

bool containsTour(vector<Tour>&, Tour&);

City eraseAndReturn(vector<City>&, const int);

int findLowerDistance(vector<City>, City);

double convertRanges(const int, const double);

#endif