//
// Created by Ale on 4/2/2025.
//

#include "Service.h"


//creates and adds a weather station to the repository
int Service::addWeatherStationService(std::string location, std::string name, std::string sensors) {
    WeatherStation newWeatherStation = WeatherStation(location, name, sensors);
    return this->repo.addWeatherStation(newWeatherStation);
}

//based on the location provides the number of stations in that location
int Service::getSortedWeatherStations(WeatherStation weather, std::string searchSensor) {
    DynamicVector<WeatherStation> sortedWeatherStations = this->repo.getRepository();
    WeatherStation aux;
    int cnt = 0;

    for(int i = 0; i < sortedWeatherStations.get_size(); i++) {
        aux = sortedWeatherStations.get_elem(i);
        if(weather.getLocation() == aux.getLocation()) {
            if(aux.getSensors().find(searchSensor)) {
                cnt++;
            }
        }
    }

    return cnt;

}
