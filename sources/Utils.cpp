#include "Utils.h"

double maxFitness(vector<Tour>& tours){
    double max = -1*numeric_limits<double>::max(), fitness{0.0};
    for(Tour t : tours){
        fitness = t.getFitness();
        if(max < fitness) max = fitness;
    }
    return(max);
}