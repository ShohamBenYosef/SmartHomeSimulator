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

    std::cout << "\nTurning on device with ID 1\n";
    myHome.turnOnDevice(1);
    std::cout << "\nTurning off device with ID 2\n";
    myHome.turnOffDevice(2);

    std::cout << "\nAfter changes:\n";
    myHome.displayAllDevices();
    
    
    
    return 0;
}