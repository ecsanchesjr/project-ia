#include <iostream>
#include <ctime>
#include "Population.hpp"
#include "ImportData.hpp"
#include "Map.hpp"

using namespace std;

int main(){
    int popSize{3};

    ImportData myFile("libs/berlin52_Edited.tsp");
    Map map(myFile.getCitiesCoord());

    Population *pop = new Population(map, popSize, 1);

    cout << (*pop) << endl;

}