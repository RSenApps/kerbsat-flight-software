#ifndef __KerbsatApp__
#define __KerbsatApp__

#include <IMUSensor.h>

class KerbSatApp
{
public:
    KerbSatApp() {};
    void setup();
    void loop();

private:
    IMUSensor imu_sensor_;
};

#endif