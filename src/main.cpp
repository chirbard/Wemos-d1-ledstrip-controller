#include <Arduino.h>
#include <FastLED.h>

#include "LedUtils.h"
#include "WifiUtils.h"

void setup()
{
  setupWifi();
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  ledsFillSolid(0, 0, 0);
}

bool once = true;
void loop()
{
  if (once)
  {
    ledsFillSolid(0, 0, 0);
    once = false;
  }
  server.handleClient();
}
