//
// Created by Ale on 4/2/2025.
//

#include "UI.h"

#include <iostream>

void print_menu() {
    std::cout << " >> add" << std::endl;
    std::cout << " >> display" << std::endl;
    std::cout << " >> filter" << std::endl;
    std::cout << " >> exit" << std::endl;
}

void UI::start() {
    while(true) {
        print_menu();
        std::string cmd;
        std::getline(std::cin, cmd);
        if (cmd == "add") {
            addWeatherStation();
            continue;
        }
        else if (cmd == "display") {
            showAllWeatherStations();
            continue;
        }
        else if (cmd == "filter") {
            showHowManyWeatherStationsLocationSensors();
            continue;
        }
        else if (cmd == "exit") {
            break;
        }
        else {
            std::cout << "Invalid Command" << std::endl;
        }
    }
}

void UI::addWeatherStation() {
    try {
        std::string location, name, sensors;
        std::cout << "Enter location: ";
        std::getline(std::cin, location);

        std::cout << "Enter name: ";
        std::getline(std::cin, name);

        std::cout << "Enter sensors: ";
        std::getline(std::cin, sensors);

        if(this->serv.addWeatherStationService(location, name, sensors) == 0) {
            std::cout << "Weather Station added" << std::endl;
        }

    }catch(...) {
        std::cout << "There was an error!" << std::endl;
    }
}

void UI::showAllWeatherStations() {
    DynamicVector<WeatherStation> weatherStations = this->serv.getWeatherStations();
    WeatherStation aux;

    for(int i = 0; i < weatherStations.get_size();i++) {
        aux = weatherStations.get_elem(i);
        std::cout << aux.getLocation() << "|" << aux.getName() << "|" << aux.getSensors() <<std::endl;
    }

    std::cout << std::endl;
}

void UI::showHowManyWeatherStationsLocationSensors() {
    DynamicVector<WeatherStation> weatherStations = this->serv.getWeatherStations();
    WeatherStation aux;

    std::string searchSensor;
    std::getline(std::cin, searchSensor);

    for(int i = 0; i < weatherStations.get_size();i++) {
        aux = weatherStations.get_elem(i);
        int numberOfSensors = this->serv.getSortedWeatherStations(aux, searchSensor);
        std::cout << aux.getLocation() << "|" << numberOfSensors << std::endl;
    }

    std::cout << std::endl;


}

