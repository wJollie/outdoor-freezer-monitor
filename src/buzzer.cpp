#include <Arduino.h>
#include "config.h"

void soundBuzzer(bool on)
{
    digitalWrite(BUZZER_PIN, on ? HIGH : LOW);
}

void beep(uint16_t ms, uint8_t times, uint16_t gap)
{
    for (uint8_t i = 0; i < times; ++i)
    {
        soundBuzzer(true);
        delay(ms);
        soundBuzzer(false);
        if (i + 1 < times)
            delay(gap);
    }
}
