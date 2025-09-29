//
// Created by Ale on 4/2/2025.
//

#include "WeatherStation.h"

WeatherStation::WeatherStation() {
    this->location = "";
    this->name = "";
    this->sensors = "";
}

WeatherStation::WeatherStation(std::string location, std::string name, std::string sensors) {
    this->location = location;
    this->name = name;
    this->sensors = sensors;
}


