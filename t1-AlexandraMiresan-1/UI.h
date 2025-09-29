//
// Created by Ale on 4/2/2025.
//

#ifndef UI_H
#define UI_H
#include "Service.h"


class UI {
private:
    Service serv;
public:
    UI(const Service s) : serv(s) {}
    void start();
private:
    void addWeatherStation();
    void showAllWeatherStations();
    void showHowManyWeatherStationsLocationSensors();
};



#endif //UI_H
