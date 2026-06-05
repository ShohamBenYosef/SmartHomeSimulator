#ifndef AIR_CONDITIONER_HPP
#define AIR_CONDITIONER_HPP

#include "Device.hpp"
#include <string>

class AirConditioner : public Device {
    private:
        int temperature; // Temperature setting in degrees Celsius

    public:
        AirConditioner(int id, const std::string& name, const std::string& location, int temperature);
        
        int getTemperature() const;
        void setTemperature(int temp);

        void displayStatus() const override;
};


#endif // AIR_CONDITIONER_HPP