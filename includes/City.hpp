#ifndef CITY_H
#define CYTY_H

#include <iostream>
#include <iomanip>

using std:: ostream;
using std:: endl;
using std:: setfill;
using std:: setw;
class City{

    friend ostream& operator<<(ostream&, const City&);

public:
    City();
    City(const int, const double, const double);

    void setId(const int);
    void setX(const double);
    void setY(const double);

    int getId() const;
    double getX() const;
    double getY() const;

    bool operator==(const City&) const;
    const City& operator=(const City&);
private:
    int id;
    double x;
    double y;
};

#endif