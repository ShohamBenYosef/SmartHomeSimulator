#include "SmartHome.hpp"
#include "Light.hpp"
#include "AirConditioner.hpp"
#include "MotionSensor.hpp"

#include <fstream>
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

int SmartHome::getDeviceCount() const {
    return devices.size();
}


bool SmartHome::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);

    if (!file) {
        throw std::runtime_error("Can't open file");
    }

    for (const auto& device : devices) {
        if (const Light* light = dynamic_cast<const Light*>(device.get())) {
            file << "LIGHT," << light->getId() << "," << light->getName() << ","
                << light->getIsOn() << "," << light->getLocation() << "," << light->getBrightness() << "\n";
        }
        else if (const AirConditioner* ac = dynamic_cast<const AirConditioner*>(device.get())) {
            file << "AC," << ac->getId() << "," << ac->getName() << ","
                << ac->getIsOn() << "," << ac->getLocation() << "," << ac->getTemperature() << "\n";
        }
        else if (const MotionSensor* ms = dynamic_cast<const MotionSensor*>(device.get())) {
            file << "MS," << ms->getId() << "," << ms->getName() << "," << ms->getIsOn() << "," 
                << ms->getLocation() << "," << ms->isMotionDetected() << "\n";
        }
    }

    return true;
}