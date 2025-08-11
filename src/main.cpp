#include <Arduino.h>
#include "config.h"

// Forward declarations
void setupSensors();
void readTemperatures();
void checkReedSwitch();
void updateLED();
void soundBuzzer(bool on);

void setup()
{
    Serial.begin(115200);

    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(REED_PIN, INPUT_PULLUP);

    setupSensors();
}

void loop()
{
    readTemperatures();
    checkReedSwitch();
    updateLED();
    delay(500);
}
