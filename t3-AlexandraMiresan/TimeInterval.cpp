//
// Created by Ale on 5/28/2025.
//

#include "TimeInterval.h"

TimeInterval::TimeInterval(int startHour, int endHour, int temperature, int precipitationProbability, std::string description) {
    this->startHour = startHour;
    this->endHour = endHour;
    this->temperature = temperature;
    this->precipitationProbability = precipitationProbability;
    this->description = description;
}
