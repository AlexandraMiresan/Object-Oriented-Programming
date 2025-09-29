//
// Created by Ale on 4/2/2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "DynamicVector.h"
#include "WeatherStation.h"


class Repository {
private:
    DynamicVector<WeatherStation> weatherStations;
public:
    int addWeatherStation(WeatherStation station);
    DynamicVector<WeatherStation> &getRepository(){return this->weatherStations;};
};



#endif //REPOSITORY_H
