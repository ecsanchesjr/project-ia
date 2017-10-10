#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <algorithm>

#include "Tour.hpp"
#include "Map.hpp"
#include "Utils.hpp"

using std::vector;
using std::ostream;
using std::setfill;
using std::setw;

extern int ELITISM_TOTAL;

class Population
{

  friend ostream &operator<<(ostream &, Population &);

public:
  Population();
  /* 
    \param1 Map of all cities in problem
    \param2 Size of Population
    \param3 Initial Population generation Method
  */
  Population(Map &, const int, const int);

  //Execute the transition beetween atual generation to next generation
  Population* newGeneration();

  vector<Tour> &getPop();

private:
  vector<Tour> pop;

  // Walks the population executing crossover in Tours.
  void crossover();

  // Walks the population executing mutation in Tours.
  void mutate(); 

  // Will chose a Tour, in pop, randomly for crossover execution
  Tour roulete();

  // Will execute mutation in Tour passed.
  void mutation(const int);

  // Runs the one-point crossover in two Tours of Population
  void crossoverOX(const int, const int);

  // Runs the Partial-Mapped Crossover in two Tours of Population
  void crossoverPMX(const int, const int);
};

#endif