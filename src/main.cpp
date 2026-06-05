#include "Light.hpp"
#include "SmartHome.hpp"
#include "AirConditioner.hpp"
#include "MotionSensor.hpp"

#include <iostream>
#include <string>
#include <vector>

void printMenu() {

    std::cout << "\nSmart Home simulator\n";
    std::cout << "--------------------\n";
    std::cout << "1. show all devices\n";
    std::cout << "0. exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    SmartHome home;
    home.addDevice(std::make_unique<Light>(1, "Living Room Light", "Living Room", 75));
    home.addDevice(std::make_unique<AirConditioner>(2, "Bedroom AC", "Bedroom", 22));
    home.addDevice(std::make_unique<MotionSensor>(3, "Hallway Sensor", "Hallway", true));

    int choice = -1;

    while (choice != 0) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                home.displayAllDevices();
                break;
            case 0:
                std::cout << "Exiting..\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }





    return 0;
}