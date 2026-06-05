#include "Light.hpp"
#include "SmartHome.hpp"
#include "AirConditioner.hpp"
#include "MotionSensor.hpp"

#include <iostream>
#include <string>
#include <vector>

int main() {
    SmartHome myHome;

    myHome.addDevice(std::make_unique<Light>(1,"Living Room Light", "Living Room", 120));
    myHome.addDevice(std::make_unique<Light>(2,"Bedroom Light", "Bedroom", 50));
    myHome.addDevice(std::make_unique<AirConditioner>(3,"Living Room AC", "Living Room", 22));
    myHome.addDevice(std::make_unique<MotionSensor>(4,"Living Room Motion Sensor", "Living Room"));
    myHome.displayAllDevices();

    std::cout << "\nTurning on device with ID 1\n";
    myHome.turnOnDevice(1);
    std::cout << "\nTurning off device with ID 2\n";
    myHome.turnOffDevice(2);
    std::cout << "\nTurning on device with ID 4\n";
    myHome.turnOnDevice(4);

    std::cout << "\nAfter changes:\n";
    myHome.displayAllDevices();
    
    std::cout << "\nRemoving device 2...\n";
    home.removeDevice(2);

    home.displayAllDevices();
    
    
    return 0;
}