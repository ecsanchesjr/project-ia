#ifndef POPULATION_H
#define POPULATION_H

#include <vector>

#include "Tour.hpp"
#include "Map.hpp"

using std::vector;
using std::ostream;
using std::setfill;
using std::setw;

class Population
{

    friend ostream &operator<<(ostream &, Population &);

  public:
    Population();
    Population(Map &, const int, const int);

    vector<Tour> &getPop();

  private:
    vector<Tour> pop;

    // Erase and Return the best Tour, use with a auxiliary Pop
    Tour elitism();

    // Runs the one-point crossover in two Tours of Population
    void crossoverOX(const int, const int);
};

#endif