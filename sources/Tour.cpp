#include "Tour.h"

Tour::Tour(){}

Tour::Tour(Map& map, const int popSize){
    // TODO generate Random
}

vector<City>& Tour::getRoute(){ return(route); }

double Tour::getFitness(){
    double sum{0.0};

    for(int i=0; i<=route.size(); i++){
        if((i+1) == route.size()){
            sum += distance(i, 0);
        }
        sum += distance(i, i+1);
    }
    dist = sum;
    return((1/sum)*RES);
}

double Tour::getDistance(){ return(dist); }

int Tour::findCity(City& c){
    for(int i=0; i<=route.size(); i++){
        if(c == route[i]) return(i);
    }
    return(-1);
}

void Tour::swapCities(const int a, const int b){
    City tmp = route[a];
    route[a] = route[b];
    route[b] = route[a];
}

double Tour::distance(const int a, const int b){
    return(sqrt(pow(route[a].getX() - route[b].getY(), 2) + pow(route[a].getY() - route[b].getY(), 2)));
}