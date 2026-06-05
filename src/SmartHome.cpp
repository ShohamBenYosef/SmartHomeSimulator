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