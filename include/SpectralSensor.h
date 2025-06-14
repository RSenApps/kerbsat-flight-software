#ifndef __SpectralSensor__
#define __SpectralSensor__

#include <Adafruit_AS7341.h>

class SpectralSensor
{
public:
    SpectralSensor() {};
    void setup();
    struct SensorVal
    {
        float basic_counts[10];
    };
    SensorVal readSensor();

private:
    Adafruit_AS7341 as7341_;
};

#endif