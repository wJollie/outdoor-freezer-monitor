#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "config.h"

// 1‑Wire bus
static OneWire oneWire(TEMP_DATA_PIN);
static DallasTemperature dt(&oneWire);

// cache
static float tempC[2] = {NAN, NAN};
static uint8_t devCount = 0;
static unsigned long lastReadMs = 0;

static void printAddress(const DeviceAddress addr)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        if (addr[i] < 16)
            Serial.print('0');
        Serial.print(addr[i], HEX);
    }
}

void setupSensors()
{
    dt.begin();
    devCount = dt.getDeviceCount();
    if (devCount > 2)
        devCount = 2;

    // Optional: set global resolution for all devices
    dt.setResolution(TEMP_RESOLUTION);

    Serial.print(F("[DS18B20] Found devices: "));
    Serial.println(dt.getDeviceCount());

    for (uint8_t i = 0; i < devCount; ++i)
    {
        DeviceAddress a;
        if (dt.getAddress(a, i))
        {
            Serial.print(F("  idx "));
            Serial.print(i);
            Serial.print(F(" addr="));
            printAddress(a);
            Serial.println();
        }
    }
}

void readTemperatures()
{
    const unsigned long now = millis();
    if (now - lastReadMs < TEMP_UPDATE_INTERVAL)
        return;
    lastReadMs = now;

    dt.requestTemperatures();

    for (uint8_t i = 0; i < devCount; ++i)
    {
        tempC[i] = dt.getTempCByIndex(i);
    }

    // friendly log
    Serial.print(F("[Temp] in="));
    Serial.print(tempC[0], 2);
    Serial.print(F("C  out="));
    Serial.print(tempC[1], 2);
    Serial.println(F("C"));
}

// --- simple getters other modules can use ---
float getInsideTempC() { return tempC[0]; }  // sensor index 0
float getOutsideTempC() { return tempC[1]; } // sensor index 1
