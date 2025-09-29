//
// Created by Ale on 4/2/2025.
//

#include "Repository.h"

//adds a weather station to the repository if that station does not already exist
int Repository::addWeatherStation(WeatherStation station) {

    WeatherStation temporary;
    for(int i = 0; i < this->weatherStations.get_size();i++) {
        temporary = this->weatherStations.get_elem(i);
        if(temporary.getLocation() == station.getLocation() && temporary.getName() == station.getName()) {
            throw std::invalid_argument("Location already exists");
        }
    }

    this->weatherStations.add(station);
    return 0;
}
