#include "City.hpp"

City::City(){
    this->id=0;
    this->x=0;
    this->y=0;
}

City::City(const int id, const double x, const double y):id(id),x(x),y(y){}

// Set/Get

void City::setId(const int id){ this->id = id; }
void City::setX(const double x){ this->x = x; }
void City::setY(const double y){ this->y = y; }

int City::getId() const { return(id); }
double City::getX()const { return(x); }
double City::getY()const { return(y); }

// ----

bool City::operator==(const City& c) const{
    return((c.getId() == this->id) ? true : false);
}

const City& City::operator=(const City& c){
    this->id = c.getId();
    this->x = c.getX();
    this->y = c.getY();
}

ostream& operator<<(ostream &output, const City &c){
    output << setfill(' ') << "ID: " << setw(2) << c.getId() << "    " << "X: "<<setw(6)<<c.getX()<< "    " << "Y: "<<setw(6)<< c.getY();
    return (output);
}