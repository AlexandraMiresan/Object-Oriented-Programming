//
// Created by Ale on 5/28/2025.
//

#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H
#include <string>


class TimeInterval {
private:
  int startHour;
  int endHour;
  int temperature;
  int precipitationProbability;
  std::string description;
public:
  TimeInterval(int startHour, int endHour, int temperature, int precipitationProbability, std::string description);
  ~TimeInterval()=default;
  int getStartHour(){return this->startHour;}
  int getEndHour(){return this->endHour;}
  int getTemperature(){return this->temperature;}
  int getPrecipitationProbability(){return this->precipitationProbability;}
  std::string getDescription(){return this->description;}

};



#endif //TIMEINTERVAL_H
