#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Population.hpp"
#include "ImportData.hpp"
#include "Map.hpp"

using namespace std;

int main()
{ // TODO Argumentos na main, atribuições de valores, não tudo na geração da pop.
    srand(time(NULL));
    int popSize{10};

    ImportData myFile("libs/berlin52.tsp");
    Map map(myFile.getCitiesCoord());

    Population *pop = new Population(map, popSize, 1, 1, 20, 1);

    int batata = 0;
    int i = 0;
    while (batata < 1000000)
    {

        Population *oldPop = pop;
        pop = (*pop).newGeneration();
        delete oldPop;

        cout << maxFitness(pop->getPop()) << endl;

        batata++;
    }
    cout << (*pop) << endl;
}