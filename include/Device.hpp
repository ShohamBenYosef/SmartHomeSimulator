#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>

class Device {
    private:
        int id;
        std::string name;
        bool isOn;
        std::string location;
    
    public:
        Device(int id, const std::string& name, const std::string& location);
        virtual ~Device() = default;
        
        int getId() const;
        const std::string& getName() const;
        const std::string& getLocation() const;
        bool getIsOn() const;

        void turnOn();
        void turnOff();
        
        virtual void displayStatus() const = 0;
};


#endif // DEVICE_HPP