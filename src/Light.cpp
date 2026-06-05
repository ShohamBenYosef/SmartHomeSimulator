#include "Light.hpp"

#include <iostream>
#include <string>

Light::Light(int id, const std::string& name, const std::string& location, int brightness)
    : Device(id,name, location), brightness(0) {
    setBrightness(brightness);
}

Light::~Light() {
    std::cout << "Destroying Light: " << getName() << std::endl;
}

int Light::getBrightness() const {
    return brightness;
}

void Light::setBrightness(int level) {
    if (level < 0) {
        brightness = 0;
    } else if (level > 100) {
        brightness = 100;
    } else {
        brightness = level;
    }
}

void Light::displayStatus() const {
    std::cout << "Light Id: " << getId()
              << "| Name: " << getName()
              << "| Location: " << getLocation() 
              << "| Status: " << (getIsOn() ? "On" : "Off")
              << "| Brightness: " << brightness << "%"
              << std::endl;
}