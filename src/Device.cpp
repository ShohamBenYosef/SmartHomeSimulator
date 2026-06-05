#include "Device.hpp"

#include <iostream>
#include <string>

Device::Device(int id, const std::string& name, const std::string& location)
    : id(id), name(name), isOn(false), location(location) {
    }

Device::~Device() {
    std::cout << "Destroying Device: " << getName() << std::endl; 
}


int Device::getId() const {
    return id;
}

const std::string& Device::getName() const {
    return name;
}

const std::string& Device::getLocation() const {
    return location;
}

bool Device::getIsOn() const {
    return isOn;
}

void Device::turnOn() {
    isOn = true;
}

void Device::turnOff() {
    isOn = false;
}
