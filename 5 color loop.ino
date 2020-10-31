#include <FastLED.h>
#define NUM_LEDS 60

// Data pin that led data will be written out over
#define DATA_PIN 5
int potPin = A2;

CRGB leds[NUM_LEDS];

uint8_t hue = 0;
void setup() {
  // put your setup code here, to run once:
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(50);
   
}



void loop() {
    int val;
    Middel(0, val);
    delay(1000);

}


void Middel(int firstled, int level){
    int middel =  (NUM_LEDS + 1) / 2;

    for (int i = 0; i < middel; i++){

        leds[middel + i] = CHSV(hue, 255, 255);
        leds[middel - i] = CHSV(hue, 255, 255);
       hue = hue + i;
    }

    FastLED.show();
}