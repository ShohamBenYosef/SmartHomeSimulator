#include "SmartHome.hpp"
#include "Light.hpp"
#include "AirConditioner.hpp"
#include "MotionSensor.hpp"

#include <iostream>
#include <memory>

void printMenu() {
    std::cout << "\n--- Smart Home Simulator ---\n";
    std::cout << "1. Show all devices\n";
    std::cout << "2. Turn on device\n";
    std::cout << "3. Turn off device\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose option: ";
}

int main() {
    SmartHome home;

    home.addDevice(std::make_unique<Light>(1, "Kitchen Light", "Kitchen", 80));
    home.addDevice(std::make_unique<AirConditioner>(2, "Living Room AC", "Living Room", 24));
    home.addDevice(std::make_unique<MotionSensor>(3, "Entrance Sensor", "Entrance"));

    int choice = -1;

    while (choice != 0) {
        printMenu();
        std::cin >> choice;

        if (choice == 1) {
            home.displayAllDevices();
        } else if (choice == 2) {
            int id;
            std::cout << "Enter device id: ";
            std::cin >> id;

            if (home.turnOnDevice(id)) {
                std::cout << "Device turned on.\n";
            } else {
                std::cout << "Device not found.\n";
            }
        } else if (choice == 3) {
            int id;
            std::cout << "Enter device id: ";
            std::cin >> id;

            if (home.turnOffDevice(id)) {
                std::cout << "Device turned off.\n";
            } else {
                std::cout << "Device not found.\n";
            }
        } else if (choice == 0) {
            std::cout << "Exiting...\n";
        } else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}