#include "SmartHome.hpp"
#include "Light.hpp"
#include "AirConditioner.hpp"
#include "MotionSensor.hpp"

#include <iostream>
#include <memory>
#include <string>

void printMenu() {
    std::cout << "\n--- Smart Home Simulator ---\n";
    std::cout << "1. Show all devices\n";
    std::cout << "2. Turn on device\n";
    std::cout << "3. Turn off device\n";
    std::cout << "4. Remove device\n";
    std::cout << "5. Add light\n";
    std::cout << "6. Add air conditioner\n";
    std::cout << "7. Add motion sensor\n";
    std::cout << "0. Exit\n";
}

int readInt(const std::string& prompt) {
    int value;

    while (true) {
        std::cout << prompt;

        if (std::cin >> value) {
            return value;
        }

        std::cout << "Invalid input. Please enter a number.\n";

        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

int main() {
    SmartHome home;

    home.addDevice(std::make_unique<Light>(1, "Kitchen Light", "Kitchen", 80));
    home.addDevice(std::make_unique<AirConditioner>(2, "Living Room AC", "Living Room", 24));
    home.addDevice(std::make_unique<MotionSensor>(3, "Entrance Sensor", "Entrance"));

    int nextId = 4;
    int choice = -1;

    while (choice != 0) {
        printMenu();
        choice = readInt("Choose option: ");

        if (choice == 1) {
            home.displayAllDevices();
        }
        else if (choice == 2) {
            int id;
            id = readInt("Enter device id: ");

            if (home.turnOnDevice(id)) {
                std::cout << "Device turned on.\n";
            } else {
                std::cout << "Device not found.\n";
            }
        }
        else if (choice == 3) {
            int id;
            id = readInt("Enter device id: ");

            if (home.turnOffDevice(id)) {
                std::cout << "Device turned off.\n";
            } else {
                std::cout << "Device not found.\n";
            }
        }
        else if (choice == 4) {
            int id;
            id = readInt("Enter device id: ");

            if (home.removeDevice(id)) {
                std::cout << "Device removed.\n";
            } else {
                std::cout << "Device not found.\n";
            }
        }
        else if (choice == 5) {
            std::string name;
            std::string location;
            int brightness;

            std::cin.ignore();

            std::cout << "Enter light name: ";
            std::getline(std::cin, name);

            std::cout << "Enter location: ";
            std::getline(std::cin, location);

            std::cout << "Enter brightness: ";
            brightness = readInt("Enter brightness: ");

            home.addDevice(std::make_unique<Light>(nextId, name, location, brightness));
            std::cout << "Light added with id " << nextId << ".\n";
            nextId++;
        }
        else if (choice == 6) {
            std::string name;
            std::string location;
            int temperature;

            std::cin.ignore();

            std::cout << "Enter AC name: ";
            std::getline(std::cin, name);

            std::cout << "Enter location: ";
            std::getline(std::cin, location);

            temperature = readInt("Enter temperature: ");

            home.addDevice(std::make_unique<AirConditioner>(nextId, name, location, temperature));
            std::cout << "Air conditioner added with id " << nextId << ".\n";
            nextId++;
        }
        else if (choice == 7) {
            std::string name;
            std::string location;

            std::cin.ignore();

            std::cout << "Enter sensor name: ";
            std::getline(std::cin, name);

            std::cout << "Enter location: ";
            std::getline(std::cin, location);

            home.addDevice(std::make_unique<MotionSensor>(nextId, name, location));
            std::cout << "Motion sensor added with id " << nextId << ".\n";
            nextId++;
        }
        else if (choice == 0) {
            std::cout << "Exiting...\n";
        }
        else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}