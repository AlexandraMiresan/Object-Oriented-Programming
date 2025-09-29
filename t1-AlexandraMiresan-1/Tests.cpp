//
// Created by Ale on 4/2/2025.
//

#include "Tests.h"

#include <cassert>

#include "Repository.h"
#include "Service.h"

void Tests::RepoTests() {
    Repository repo = Repository();
    WeatherStation station = WeatherStation("Cluj", "Babes", "Thermometer");
    repo.addWeatherStation(station);
    DynamicVector<WeatherStation> weatherStations;
    //weatherStations = repo.getRepository();
    //assert(weatherStations.get_size() != 0);

}

void Tests::ServiceTests() {
    Repository repo = Repository();
    Service serv = Service(repo);

    serv.addWeatherStationService("Cluj", "Babes", "Thermometer");
    DynamicVector<WeatherStation> weatherStations = serv.getWeatherStations();
   // assert(weatherStations.get_size() != 0);

}

void Tests::runAllTests() {
    // Tests::RepoTests();
    // Tests::ServiceTests();
}

