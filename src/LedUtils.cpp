#include "LedUtils.h"

CRGB leds[NUM_LEDS];

void ledsFillSolid(int hue, int saturation, int luma)
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = CHSV(hue, saturation, luma);
    }
    FastLED.show();
}
