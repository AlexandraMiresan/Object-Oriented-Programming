//
// Created by Ale on 4/2/2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <algorithm>

#include "Repository.h"


class Service {
private:
    Repository repo;
public:
    explicit Service(Repository r) : repo(std::move(r)) {}
    int addWeatherStationService(std::string location, std::string name, std::string sensors);
    DynamicVector<WeatherStation> &getWeatherStations(){return this->repo.getRepository();};
    int getSortedWeatherStations(WeatherStation weather, std::string sensor);
};



#endif //SERVICE_H
