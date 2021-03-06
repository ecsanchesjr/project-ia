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
extern int CROSS_METHOD;
extern int MUT_PERCENTAGE;
extern int ELITISM_TOTAL;

const int RES = 10000; // Number to improve the visualization of fitness values.
extern vector<City> firstPoint; // Save the cities to random-first generation

/*----------------------
    Utilities Functions
------------------------*/

bool compareDouble(const double,const double);

double maxFitness(vector<Tour>&);

double distance(City&, City&);

bool contains(vector<City>&, City&);

City eraseAndReturn(vector<City>&, const int);

int findLowerDistance(vector<City>, City);

double convertRanges(const int, const double);

bool ALargerB(Tour&, Tour&);

// Erase and Return the best Tour, use with a auxiliary Pop
vector<Tour> elitism(vector<Tour>&);

int bestFitness(vector<Tour>&);

#endif