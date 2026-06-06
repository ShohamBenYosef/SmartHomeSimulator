#include "DeviceFactory.hpp"
#include "Light.hpp"
#include "AirConditioner.hpp"
#include "MotionSensor.hpp"


std::unique_ptr<Device> DeviceFactory::createLight(int id, const std::string& name, const std::string& location, int brightness) {
    return std::make_unique<Light>(id, name, location, brightness);
}  

std::unique_ptr<Device> DeviceFactory::createAirConditioner(int id, const std::string& name, const std::string& location, int temperature) {
    return std::make_unique<AirConditioner>(id, name, location, temperature);
}

std::unique_ptr<Device> DeviceFactory::createMotionSensor(int id, const std::string& name, const std::string& location) {
    return std::make_unique<MotionSensor>(id, name, location);
}