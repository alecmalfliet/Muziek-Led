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
    int val = analogRead(potPin);
    val = map(val, 0, 1023, 0, 60);
    VolumeLevel(0, val);

}

/*
Kleur verdeeling 
Groen:10 Geel:6 Rood:4
Groen: 5/10 Geel: 3/10 Rood: 2/10
*/

void VolumeLevel(int firstled, int level){
    for (int i = 0; i < level; i++){
        i = i + firstled;
        if (i < 30){
            leds[i] = CHSV(100, 255, 255);
        } else if (i < 48){
            leds[i] = CHSV(40, 255, 255);
        } else if (i < 60){
            leds[i] = CHSV(5, 255, 255);
        }
    }
    for (int i = level; i < 60; i++){
        i = i + firstled;
        leds[i] = CHSV(0, 0, 0);
    }
    FastLED.show();
}