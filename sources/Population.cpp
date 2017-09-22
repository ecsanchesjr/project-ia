#include "Population.h"

Population::Population(){}

Population::Population(Map& map, const int popSize){
    pop.push_back(Tour(map, popSize));
}

vector<Tour>& Population::getPop(){ return(pop); }

Tour elitism(){
    
}