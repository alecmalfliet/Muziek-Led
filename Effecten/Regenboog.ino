#include <FastLED.h>
#define NUM_LEDS 60

// Data pin that led data will be written out over
#define DATA_PIN 5

CRGB leds[NUM_LEDS];

uint8_t hue = 0;
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i * 10, 255, 150);
  }

  EVERY_N_MILLISECONDS(15){
    hue++;
  }
  
  FastLED.show();
}