#ifndef MAP_H
#define MAP_H

#include <vector>
#include "City.hpp"

using std::vector;

class Map{
    
public:
    Map(vector<City>);
    vector<City>& getCityList();
private:
    vector<City> cityList;
};

#endif