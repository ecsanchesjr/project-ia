#include "Map.h"

Map::Map(vector<City> data):cityList(data){}

vector<City>& Map::getCityList(){ return(cityList); }

