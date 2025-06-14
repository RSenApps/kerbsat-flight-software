#include <KerbSatApp.h>

void KerbSatApp::setup()
{
    imu_sensor_.setup();
    spectral_sensor_.setup();
    lora_radio_.setup();
}

void KerbSatApp::loop()
{
    imu_sensor_.readSensor();
    spectral_sensor_.readSensor();
    lora_radio_.sendMessage();
}