#ifndef MOTION_SENSOR_HPP
#define MOTION_SENSOR_HPP

#include "Device.hpp"
#include <string>


class MotionSensor : public Device {
    private:
        bool motionDetected; // Indicates if motion is currently detected

    public:
        MotionSensor(int id, const std::string& name, const std::string& location);
        
        bool isMotionDetected() const;
        void setMotionDetected(bool detected);

        void displayStatus() const override;
};





#endif // MOTION_SENSOR_HPP