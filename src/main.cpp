#include <Arduino.h>

#include <KerbSatApp.h>

KerbSatApp app;

void setup()
{
    Serial.begin(9600);

    while (!Serial)
        delay(10); // wait for serial port to open!

    Serial.println("Starting setup");
    app.setup();
    Serial.println("Setup complete");
}

void loop()
{
    app.loop();
}