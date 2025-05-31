#ifndef __KerbsatApp__
#define __KerbsatApp__

#include <IMUSensor.h>
#include <LoraRadio.h>

class KerbSatApp
{
public:
    KerbSatApp() {};
    void setup();
    void loop();

private:
    IMUSensor imu_sensor_;
    LoraRadio lora_radio_;
};

#endif