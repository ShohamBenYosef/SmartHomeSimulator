#include "MotionSensor.hpp"

#include <iostream>

MotionSensor::MotionSensor(int id, const std::string& name, const std::string& location)
    : Device(id, name, location), motionDetected(false) {
}

MotionSensor::~MotionSensor() {
    std::cout << "Destroying Motion Sensor: " << getName() << std::endl; 
}

bool MotionSensor::isMotionDetected() const {
    return motionDetected;
}

void MotionSensor::setMotionDetected(bool detected) {
    motionDetected = detected;
}

void MotionSensor::displayStatus() const {
    std::cout << "Motion Sensor Id: " << getId()
              << " | Name: " << getName()
              << " | Location: " << getLocation()
              << " | Status: " << (getIsOn() ? "On" : "Off")
              << " | Motion: " << (motionDetected ? "Detected" : "No Motion")
              << std::endl;
}