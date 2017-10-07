/*==============================================================
    Arguments to Run

    \param1 Name of .tsp file (with .tsp in name)
    \param2 Name of log file
    \param3 Size of Population 
    \param4 Initial Population generation Method
        -> '0' to random method
        -> '1' to improved method
    \param5 Crossover method 
        -> '0' to Crossover OX
        -> '1' to Crossover PMX
    \param6 Elitism percentage (0 - 100)
    \param7 Mutation percentage (0 - 100)
================================================================*/

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Population.hpp"
#include "ImportData.hpp"
#include "ExportData.hpp"
#include "Map.hpp"

using std::cout;
using std::endl;
using std::stoi;

const int LIM_UNCHANGED{5000};

extern int ELITISM_TOTAL;

unsigned int popSize{0};
string inputFileName{""};
string outputFileName{""};
unsigned int generationMethod;

void initAlg();
bool endAlg(Population&);

int main(int argc, char *argv[]){
    if(argc != 8){
        std::cerr << "Number of params incorrect!" << endl;
        return(0);
    }

    try{
        inputFileName = argv[1];
        outputFileName = argv[2];
        popSize = stoi(argv[3]);
        generationMethod = stoi(argv[4]);
        CROSS_METHOD = stoi(argv[5]);
        ELITISM_TOTAL = (float)stoi(argv[6])/100 * popSize;
        MUT_PERCENTAGE = stoi(argv[7]);
    }catch(std::invalid_argument &e){
        std::cerr << "Error in param!" << endl;
    }
    initAlg();
    return(0);
}

void initAlg(){
    unsigned long int gen{0};
    srand(time(NULL));

    ImportData inputStream("libs/"+inputFileName);
    ExportData outputStream("logs/"+outputFileName);
    std::ostringstream input;

    Map map(inputStream.getCitiesCoord()); // Map generation

    Population *pop = new Population(map, popSize, generationMethod);

    while(!endAlg(*pop)){ // While stop condition not executed
        
        Population *oldPop = pop;
        pop = (*pop).newGeneration();
        delete oldPop;
        gen++;
        if(gen%1000==0){
            cout << "Generation: " << gen << endl;
            input.str("");
            input.clear();
            input << gen << " " << maxFitness(pop->getPop());
            outputStream.writeFile(input); 
        }
    } 
    for(Tour t : pop->getPop()){
        cout << t.getFitness() << endl;
    }
    cout << "Stop condition executed!!" << endl;
}

bool endAlg(Population &pop){
    static long int genWithoutChanges{0};
    static double maxFitEver{0.0};
    double maxFitNow{maxFitness(pop.getPop())};
    if(maxFitNow > maxFitEver){
        maxFitEver = maxFitNow;
        genWithoutChanges = 0;
        cout << "Increased Maximum Fitness!" << endl;
        cout << "Fitness: " << maxFitEver << "\t" << "Distance: " << ((1/maxFitEver)*10000) << endl;
    }else{
        genWithoutChanges++;
    }

    if(genWithoutChanges >= LIM_UNCHANGED){
        return(true);
    }else{
        return(false);
    }
}