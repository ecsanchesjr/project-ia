#ifndef TOUR_H
#define TOUR_H

#include<vector>
#include<cmath>

#include "Utils.h"
#include "Map.h"

using std::vector;

class Tour{

public:
    Tour();
    Tour(Map&, const int);
    vector<City>& getRoute();
    double getFitness();
    double getDistance();
    void swapCities(const int, const int);
    int findCity(City&);

private:
    vector<City> route;
    double dist{0};
    double distance(const int, const int);
};

#endif