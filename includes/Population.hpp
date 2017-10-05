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

  // Will chose a Tour, in pop, randomly for crossover execution
  Tour roulete();

  // Erase and Return the best Tour, use with a auxiliary Pop
  Tour elitism();

  // Will execute mutation in Tour passed.
  void mutation(const int);

  // Runs the one-point crossover in two Tours of Population
  void crossoverOX(const int, const int);

  // Runs the Partial-Mapped Crossover in two Tours of Population
  void crossoverPMX(const int, const int);
};

#endif