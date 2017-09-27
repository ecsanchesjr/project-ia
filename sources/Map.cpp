#include "Map.hpp"

Map::Map(vector<City> data):cityList(data){}

vector<City>& Map::getCityList(){ return(cityList); }

