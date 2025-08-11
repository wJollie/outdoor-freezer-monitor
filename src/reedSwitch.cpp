#include <Arduino.h>
#include "config.h"

// Provided by buzzer.cpp
void soundBuzzer(bool on);
void beep(uint16_t ms = 50, uint8_t times = 1, uint16_t gap = 50);

// Debounce
static bool doorOpen = false;
static bool lastStable = false;
static uint32_t lastChange = 0;
static const uint16_t DEBOUNCE_MS = 25;

bool isDoorOpen() { return doorOpen; }

void checkReedSwitch()
{
    // With INPUT_PULLUP: open switch -> HIGH, closed -> LOW
    bool raw = digitalRead(REED_PIN) == HIGH; // HIGH means door open

    if (raw != lastStable)
    {
        if (millis() - lastChange > DEBOUNCE_MS)
        {
            lastStable = raw;
            lastChange = millis();

            doorOpen = raw;
            Serial.print(F("[Door] "));
            Serial.println(doorOpen ? F("OPEN") : F("CLOSED"));

            // one short beep on transitions
            beep(40, 1, 0);
        }
    }
    else
    {
        lastChange = millis();
    }
}
