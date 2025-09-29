//
// Created by Ale on 6/25/2025.
//

#ifndef LOCATION_H
#define LOCATION_H



class Location {
private:
  int latitudeX;
  int longitudeX;
  int latitudeY;
  int longitudeY;
public:
  Location(int latitudeX,int latitudeY, int longitudeX, int longitudeY):latitudeX(latitudeX),latitudeY(latitudeY),longitudeX(longitudeX),longitudeY(longitudeY){}
  int getLatitudeX(){return this->latitudeX;}
  int getLatitudeY(){return this->latitudeY;}
  int getLongitudeX(){return this->longitudeX;}
  int getLongitudeY(){return this->longitudeY;}
  ~Location()=default;
};



#endif //LOCATION_H
