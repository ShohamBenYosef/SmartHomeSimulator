#include "SmartHome.hpp"

#include <iostream>
#include <vector>
#include <memory>


void SmartHome::addDevice(std::unique_ptr<Device> device) {
    devices.push_back(std::move(device));
}


void SmartHome::displayAllDevices() const {
    for (const auto& device : devices) {
        device->displayStatus();
    }
}

Device* SmartHome::getDeviceById(int id) {
    for (const auto& dev : devices) {
        if (dev->getId() == id) {
            return dev.get();
        }
    }
    return nullptr; // Return nullptr if device not found
}

bool SmartHome::turnOnDevice(int id) {
    Device* dev = getDeviceById(id);
    if (dev) {
        dev->turnOn();
        return true;
    }
    return false; // Device not found
}

bool SmartHome::turnOffDevice(int id) {
    Device* dev = getDeviceById(id);
    if (dev) {
        dev->turnOff();
        return true;
    }
    return false; // Device not found
}

bool SmartHome::removeDevice(int id) {
    for (auto dev = devices.begin(); dev != devices.end(); ++dev) {
        if ((*dev)->getId() == id) {
            devices.erase(dev);
            return true; // Device removed
        }
    }
    return false; // Device not found
}