#include "Population.hpp"

Population::Population(){}

Population::Population(Map& map, const int popSize, const int generateMode){
    for(int i=0; i<popSize; i++){
        pop.push_back(Tour(map, generateMode));
    }
}

vector<Tour>& Population::getPop(){ return(pop); }

Tour Population::elitism(){
    
}

ostream& operator<<(ostream &output,Population &pop){  // Overload de operador para impressão da população
    int i{0};
    for(Tour t : pop.getPop()){
        output<<"Tour "<<setfill('0')<<setw(3)<<i<<endl;
        output<<t<<endl;
        ++i;
    }
    return(output);
}
