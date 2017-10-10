#include "Utils.hpp"

int ELITISM_TOTAL=0;
int CROSS_METHOD=0;
int MUT_PERCENTAGE=0;

vector<City> firstPoint;

bool compareDouble(const double a, const double b){
    return(fabs(a-b)<numeric_limits<double>::epsilon());
}

double maxFitness(vector<Tour>& tours){
    double max = numeric_limits<double>::min(), fitness{0.0};
    for(Tour t : tours){
        fitness = t.getFitness();
        if(max < fitness){ 
            max = fitness; 
        }
    }
    return(max);
}

double distance(City& c1,City& c2){  // Retorno da distancia entre duas cidades
    return(sqrt(pow(c1.getX()-c2.getX(),2)+pow(c1.getY()-c2.getY(),2)));
}

bool contains(vector<City> &vec,City &c){  // Irá verificar se a cidade já existe no Tour
    for(City objC : vec){
        if(objC == c){
            return(true);
        }
    }
    return(false);
}

City eraseAndReturn(vector<City>& map, const int index){
    City tmp = map[index];
    map.erase(map.begin() + index);
    return(tmp);
} 

int findLowerDistance(vector<City> map, City atual){
    double lower{numeric_limits<double>::max()};
    int index{-1};

    for(int i=0; i<map.size(); i++){
        if(lower > distance(map[i], atual)){
            if(distance(map[i],atual)!=0){
                index=i;
                lower = distance(map[i], atual);
            }
        }
    }
    return(index);
}

double convertRanges(const int n,const double rand){ 
    return((rand*n)/RES);
}

bool ALargerB(Tour& t1, Tour& t2){
    return (t1.getFitness() > t2.getFitness());
}

vector<Tour> elitism(vector<Tour>& tours){
    vector<Tour> elitism;

    std::sort(tours.begin(), tours.end(), ALargerB);

    for(int i=0; i<ELITISM_TOTAL; i++){
        elitism.push_back(tours[i]);
    }

    return(elitism);
}
