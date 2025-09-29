//
// Created by Ale on 4/2/2025.
//

#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H
#include <string>


class WeatherStation {
private:
    std::string location;
    std::string name;
    std::string sensors;
public:
    WeatherStation();
    WeatherStation(std::string location, std::string name, std::string sensors);
    std::string getLocation() {return this->location;};
    std::string getName(){return this->name;};
    std::string getSensors(){return this->sensors;};
};



#endif //WEATHERSTATION_H
