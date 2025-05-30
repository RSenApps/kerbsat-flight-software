#include <KerbSatApp.h>

void KerbSatApp::setup()
{
    imu_sensor_.setup();
}

void KerbSatApp::loop()
{
    imu_sensor_.readSensor();
}