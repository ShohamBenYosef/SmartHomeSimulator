#include "SmartHome.hpp"
#include "DeviceFactory.hpp"

#include <iostream>
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
    std::cout << "8. Save devices to file\n";
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

std::string readLine(const std::string& prompt) {
    std::string value;

    std::cout << prompt;
    std::getline(std::cin >> std::ws, value);

    return value;
}

void addLight(SmartHome& home, int& nextId) {
    std::string name = readLine("Enter light name: ");
    std::string location = readLine("Enter location: ");
    int brightness = readInt("Enter brightness: ");

    home.addDevice(DeviceFactory::createLight(nextId, name, location, brightness));
    std::cout << "Light added with id " << nextId << ".\n";
    nextId++;
}

void addAirConditioner(SmartHome& home, int& nextId) {
    std::string name = readLine("Enter AC name: ");
    std::string location = readLine("Enter location: ");
    int temperature = readInt("Enter temperature: ");

    home.addDevice(DeviceFactory::createAirConditioner(nextId, name, location, temperature));
    std::cout << "Air conditioner added with id " << nextId << ".\n";
    nextId++;
}

void addMotionSensor(SmartHome& home, int& nextId) {
    std::string name = readLine("Enter sensor name: ");
    std::string location = readLine("Enter location: ");

    home.addDevice(DeviceFactory::createMotionSensor(nextId, name, location));
    std::cout << "Motion sensor added with id " << nextId << ".\n";
    nextId++;
}

int main() {
    SmartHome home;

    home.addDevice(DeviceFactory::createLight(1, "Kitchen Light", "Kitchen", 80));
    home.addDevice(DeviceFactory::createAirConditioner(2, "Living Room AC", "Living Room", 24));
    home.addDevice(DeviceFactory::createMotionSensor(3, "Entrance Sensor", "Entrance"));

    int nextId = 4;
    int choice = -1;

    while (choice != 0) {
        printMenu();
        choice = readInt("Choose option: ");

        if (choice == 1) {
            home.displayAllDevices();
        }
        else if (choice == 2) {
            int id = readInt("Enter device id: ");
            std::cout << (home.turnOnDevice(id) ? "Device turned on.\n" : "Device not found.\n");
        }
        else if (choice == 3) {
            int id = readInt("Enter device id: ");
            std::cout << (home.turnOffDevice(id) ? "Device turned off.\n" : "Device not found.\n");
        }
        else if (choice == 4) {
            int id = readInt("Enter device id: ");
            std::cout << (home.removeDevice(id) ? "Device removed.\n" : "Device not found.\n");
        }
        else if (choice == 5) {
            addLight(home, nextId);
        }
        else if (choice == 6) {
            addAirConditioner(home, nextId);
        }
        else if (choice == 7) {
            addMotionSensor(home, nextId);
        }
        else if (choice == 8) {
            if (home.saveToFile("devices.txt")) {
                std::cout << "Devices saved.\n";
            } else {
                std::cout << "Failed to save devices.\n";
            }
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