#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Device.hpp"
#include <string>

class Light : public Device {
    private:
        int  brightness; // Brightness level from 0 to 100

    public:
        Light(int id, const std::string& name, const std::string& location, int brightness);
        
        int getBrightness() const;
        void setBrightness(int level);

        void displayStatus() const override;
};

#endif // LIGHT_HPP