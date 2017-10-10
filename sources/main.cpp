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
#include <chrono>
#include "Population.hpp"
#include "ImportData.hpp"
#include "ExportData.hpp"
#include "Map.hpp"

using std::cout;
using std::endl;
using std::stoi;

typedef std::chrono::high_resolution_clock Clock;

const int LIM_UNCHANGED{50000};
const int LIM_ALL{1000000};

extern int ELITISM_TOTAL;

unsigned int popSize{0};
string inputFileName{""};
string outputFileName{""};
string outputSolution{""};
unsigned int generationMethod;
unsigned long int gen{0};

void initAlg();
bool endAlg(Population&);

int main(int argc, char *argv[]){
    if(argc != 9){
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
        outputSolution = argv[8];
    }catch(std::invalid_argument &e){
        std::cerr << "Error in param!" << endl;
    }
    //auto t0 = Clock::now(); // Init time metrics
    initAlg();
    //auto tF = Clock::now();    

    //int exeTime = std::chrono::duration_cast<std::chrono::seconds>(tF - t0).count();
    //cout << "Execution time: " << exeTime << " seconds!" <<  endl;

    return(0);
}

void initAlg(){
    srand(time(NULL));

    ImportData inputStream(inputFileName);
    ExportData outputStream(outputFileName);
    ExportData outputSolStream(outputSolution);
    std::ostringstream input;
    std::ostringstream inputSol;
    double fitnessRunning{0.0};

    Map map(inputStream.getCitiesCoord()); // Map generation

    Population *pop = new Population(map, popSize, generationMethod);

    input.str("");
    input.clear();
    fitnessRunning = maxFitness(pop->getPop());
    input << gen << " , " << fitnessRunning << " , " << ((1/fitnessRunning)*10000);
    outputStream.writeFile(input); 

     while(!endAlg(*pop)){ // While stop condition not executed
        
        Population *oldPop = pop;
        pop = (*pop).newGeneration();
        delete oldPop;
        gen++;
        if(gen%100==0){
            //cout << "Generation: " << gen << endl;
            input.str("");
            input.clear();
            fitnessRunning = maxFitness(pop->getPop());
            input << gen << " , " << fitnessRunning << " ," << ((1/fitnessRunning)*10000);
            outputStream.writeFile(input); 
        }
    }

    Tour sol = pop->getPop()[bestFitness(pop->getPop())];
    for(City c : sol.getRoute()){
        inputSol.str("");
        inputSol.clear();
        inputSol << c.getId();
        outputSolStream.writeFile(inputSol);
    }
    //cout << "Stop condition executed!!" << endl;    

    cout << ((1/maxFitness(pop->getPop()) * 10000)) << endl;
}

bool endAlg(Population &pop){
    static long int genWithoutChanges{0};
    static double maxFitEver{0.0};
    double maxFitNow{maxFitness(pop.getPop())};
    if(maxFitNow > maxFitEver){
        maxFitEver = maxFitNow;
        genWithoutChanges = 0;
        //cout << "Increased Maximum Fitness!" << endl;
        //cout << "Fitness: " << maxFitEver << "\t" << "Distance: " << ((1/maxFitEver)*10000) << endl;
    }else{
        genWithoutChanges++;
    }
    
    if(genWithoutChanges >= LIM_UNCHANGED){
        return(true);
    }else if (gen == LIM_ALL){
        return(true);
    }else{
        return(false);
    }
}