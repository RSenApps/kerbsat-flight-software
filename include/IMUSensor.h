#ifndef __BNO055Sensor__
#define __BNO055Sensor__

#include <Adafruit_BNO055.h>

class IMUSensor
{
public:
    IMUSensor() {};
    void setup();
    struct SensorVal
    {
        float orientationX;
        float orientationY;
        float orientationZ;
    };
    SensorVal readSensor();

private:
    Adafruit_BNO055 bno_ = Adafruit_BNO055(55, 0x28, &Wire);
    bool sensor_ready_ = false;
};

#endif