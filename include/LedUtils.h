#ifndef LEDUTILS_H
#define LEDUTILS_H

#include <FastLED.h>

#define NUM_LEDS 20
#define DATA_PIN D4

extern CRGB leds[NUM_LEDS];

void ledsFillSolid(int hue, int saturation, int luma);

#endif