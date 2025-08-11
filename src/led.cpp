#include <Arduino.h>
#include "config.h"

// Provided by sensors.cpp
float getInsideTempC();
bool isDoorOpen();

// tweakable
static const float WARN_C = -5.0f; // e.g. warn if inside > -5°C

void updateLED()
{
    const bool door = isDoorOpen();
    const float tin = getInsideTempC();

    bool warnHot = (!isnan(tin) && tin > WARN_C);

    digitalWrite(LED_PIN, (door || warnHot) ? HIGH : LOW);
}
