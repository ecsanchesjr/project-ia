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
  /* 
    \param1 Map of all cities in problem
    \param2 Size of Population
    \param3 Initial Population generation Method, default = 0 (random)
    \param4 Crossover method, default = 0 (OX)
    \param5 Eletism percentage, default = 20 (20%)
    \param6 Mutation percentage, default = 5 (5%)
  */
  Population(Map &, const int popSize, const int generationMethod = 0, const int crossMethod = 0, const int elitism = 20, const int mutPerc = 5);

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