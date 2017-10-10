#include "Tour.hpp"

Tour::Tour(){}

Tour::Tour(Map& map, const int generateMode){
    Map tmp(map.getCityList());
    
    if(generateMode==0){
        randomGeneration(tmp.getCityList());
    }else if(generateMode==1){
        firstRandomGeneration(tmp);
    }else{ // Never catch in this else
        cout << "GenerateMode value ERROR!!!" << endl;
    }
}

vector<City>& Tour::getRoute(){ return(route); }

double Tour::getFitness(){
    double sum{0.0};

    for(int i=0; i<route.size(); i++){
        if((i+1) == route.size()){
            sum += distance(i, 0);
        }else{
            sum += distance(i, i+1);        
        }
    }

    dist = sum;
    return((1/sum)*10000);
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
    route[b] = tmp;
}

double Tour::distance(const int a, const int b){
    return(sqrt(pow(((route)[a].getX())-((route)[b].getX()),2)+pow(((route)[a].getY())-((route)[b].getY()),2)));
}

void Tour::randomGeneration(vector<City> &map){
    for (City c : map){
        route.push_back(c);
    }
    for(int i=0; i<10*route.size(); i++){
        swapCities(rand()%route.size(), rand()%route.size());
    }
}

void Tour::firstRandomGeneration(Map &map){
    int size{(int)map.getCityList().size()};
    int indexFirst{rand()%size};
    int ctrl{0}, batata{0};
    
    while(contains(firstPoint,map.getCityList()[indexFirst]) && firstPoint.size() < size){
        indexFirst=rand()%size;
    }
    (route).push_back(eraseAndReturn(map.getCityList(), indexFirst));
    size--;

    firstPoint.push_back(route[0]);
       
    while(size!=0){
        (route).push_back(eraseAndReturn(map.getCityList(), findLowerDistance(map.getCityList(), (route)[ctrl])));
        size--;
        ctrl++;
    }  
}

bool Tour::operator==(Tour& t){
    for(int i=0; i<t.getRoute().size(); i++){
        if(!(t.getRoute()[i] == this->getRoute()[i])){
            return(false);
        }
    }
    return(true);
}

ostream& operator<<(ostream &output,Tour &t){  // Overload de operador para impressão da população
    //int i=0;
    for(City c : t.getRoute()){
        output << setfill(' ') << c << endl;
        //output<< i << " " << setfill(' ') <<c<<endl; i++; // Debug
    }
    output<<"Fitness: "<<t.getFitness()<<endl;
    output<<"Distance: "<<t.dist<<endl;
    return(output);
}