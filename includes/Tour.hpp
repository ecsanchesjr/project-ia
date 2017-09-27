#ifndef TOUR_H
#define TOUR_H

#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>

#include "Map.hpp"

class Tour;
#include "Utils.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::ostream;
using std::setfill;
using std::setw;

class Tour{

    friend ostream& operator<<(ostream&,Tour &);

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
    void randomGeneration(vector<City>&);
    void firstRandomGeneration(Map&);
};

#endif