#ifndef DEVICE_FACTORY_HPP
#define DEVICE_FACTORY_HPP

#include <memory>
#include "Device.hpp"

class DeviceFactory {
    public:
        static std::unique_ptr<Device> createLight(int id, const std::string& name, const std::string& location, int brightness);
        static std::unique_ptr<Device> createAirConditioner(int id, const std::string& name, const std::string& location, int temperature);
        static std::unique_ptr<Device> createMotionSensor(int id, const std::string& name, const std::string& location);
};



#endif // DEVICE_FACTORY_HPP