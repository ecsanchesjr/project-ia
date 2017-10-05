#include <iostream>
#include <ctime>
#include "Population.hpp"
#include "ImportData.hpp"
#include "Map.hpp"

using namespace std;

int main(){
    int popSize{1};

    ImportData myFile("libs/berlin52_Edited.tsp");
    Map map(myFile.getCitiesCoord());

    Population *pop = new Population(map, popSize, 1, 1, 20, 1);
    //cout << (*pop) << endl;
}