#include "Light.hpp"
#include "SmartHome.hpp"

#include <iostream>
#include <string>
#include <vector>

int main() {
    SmartHome myHome;

    myHome.addDevice(std::make_unique<Light>(1,"Living Room Light", "Living Room", 120));
    myHome.addDevice(std::make_unique<Light>(2,"Bedroom Light", "Bedroom", 50));
    myHome.displayAllDevices();

    return 0;
}