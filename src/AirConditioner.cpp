#include "AirConditioner.hpp"

#include <iostream>


AirConditioner::AirConditioner(int id, const std::string& name, const std::string& location, int temperature)
    : Device(id, name, location), temperature(16) { // Default to minimum temperature
        setTemperature(temperature); // Use setter to validate temperature
    }


int AirConditioner::getTemperature() const {
    return temperature;
}

void AirConditioner::setTemperature(int temp) {
    if (temp < 16) {
        temperature = 16; // Minimum temperature
    } else if (temp > 30) {
        temperature = 30; // Maximum temperature
    } else {
        temperature = temp;
    }
}

void AirConditioner::displayStatus() const {
    std::cout << "Air Conditioner Id: " << getId()
              << "| Name: " << getName()
              << "| Location: " << getLocation() 
              << "| Status: " << (getIsOn() ? "On" : "Off")
              << "| Temperature: " << temperature << "°C"
              << std::endl;
}