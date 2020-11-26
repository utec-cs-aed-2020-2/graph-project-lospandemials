#ifndef AIRPORT_H
#define AIRPORT_H

#include "../lib.h"

class Airport{
private:
    std::string city;
    std::string name;
    std::string country;
    double longitude;
    double latitude;

public:
    Airport(){}
    ~Airport(){}
    Airport(std::string city, std::string name, std::string country, double longitude, double latitude){
        this->city = city;
        this->name = name;
        this->country = country;
        this->longitude = longitude;
        this->latitude = latitude;
    }
    Airport(const Airport &o){
        this->city = o.city;
        this->name = o.name;
        this->country = o.country;
        this->longitude = o.longitude;
        this->latitude = o.latitude;
    }
    Airport& operator=(const Airport& o){
        this->city = o.city;
        this->name = o.name;
        this->country = o.country;
        this->longitude = o.longitude;
        this->latitude = o.latitude;
        return *this;
    }
    double operator-(const Airport& o){
        return sqrt((this->longitude - o.longitude)*(this->longitude - o.longitude) + (this->latitude - o.latitude)*(this->latitude - o.latitude));
    }
    bool operator==(const Airport& airport){
        return this->city == airport.city &&
               this->name == airport.name &&
               this->country == airport.country &&
               this->longitude == airport.longitude &&
               this->latitude == airport.latitude;
    }
    bool operator!=(const Airport& airport){
        return this->city != airport.city ||
               this->name != airport.name ||
               this->country != airport.country ||
               this->longitude != airport.longitude ||
               this->latitude != airport.latitude;
    }
    friend std::ostream &operator<<(std::ostream &os, const Airport &o){ 
        os << o.name << " [" << o.city << ", " << o.country << "] ";
        return os;
    }
};

#endif