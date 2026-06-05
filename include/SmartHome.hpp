#ifndef SMART_HOME_HPP
#define SMART_HOME_HPP

#include "Device.hpp"

#include <vector>
#include <memory>

class SmartHome {
    private:
        std::vector<std::unique_ptr<Device>> devices;
    
    public:
        void addDevice(std::unique_ptr<Device> device);
        void displayAllDevices() const;
};


#endif // SMART_HOME_HPP