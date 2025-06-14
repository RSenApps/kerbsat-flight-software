#include <SpectralSensor.h>

void SpectralSensor::setup()
{
    if (!as7341_.begin(0x39, &Wire))
    {
        Serial.println("Could not find AS7341");
        while (1)
        {
            delay(10);
        }
    }
    as7341_.setATIME(100);
    as7341_.setASTEP(999);
    as7341_.setGain(AS7341_GAIN_256X);
}

SpectralSensor::SensorVal SpectralSensor::readSensor()
{
    uint16_t readings[12];
    SensorVal sensor_val;
    if (!as7341_.readAllChannels(readings))
    {
        Serial.println("Error reading all channels!");
        return sensor_val;
    }

    uint8_t basic_counts_idx = 0;
    for (uint8_t i = 0; i < 12; i++)
    {
        if (i == 4 || i == 5)
            continue;
        // we skip the first set of duplicate clear/NIR readings
        // (indices 4 and 5)
        sensor_val.basic_counts[basic_counts_idx++] = as7341_.toBasicCounts(readings[i]);
    }

    Serial.print("F1 415nm : ");
    Serial.println(sensor_val.basic_counts[0]);
    Serial.print("F2 445nm : ");
    Serial.println(sensor_val.basic_counts[1]);
    Serial.print("F3 480nm : ");
    Serial.println(sensor_val.basic_counts[2]);
    Serial.print("F4 515nm : ");
    Serial.println(sensor_val.basic_counts[3]);
    Serial.print("F5 555nm : ");
    // again, we skip the duplicates
    Serial.println(sensor_val.basic_counts[6]);
    Serial.print("F6 590nm : ");
    Serial.println(sensor_val.basic_counts[7]);
    Serial.print("F7 630nm : ");
    Serial.println(sensor_val.basic_counts[8]);
    Serial.print("F8 680nm : ");
    Serial.println(sensor_val.basic_counts[9]);
    Serial.print("Clear    : ");
    Serial.println(sensor_val.basic_counts[10]);
    Serial.print("NIR      : ");
    Serial.println(sensor_val.basic_counts[11]);
    return sensor_val;
}