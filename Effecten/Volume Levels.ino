#include <FastLED.h>
#define NUM_LEDS 60

// Data pin that led data will be written out over
#define DATA_PIN 5

const int OUT_PIN = 8;
const int SAMPLE_TIME = 15;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int val;
int sampleBufferValue = 0;
int minn;

CRGB leds[NUM_LEDS];

uint8_t hue = 0;
void setup() {
  // put your setup code here, to run once:
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(50);
   
}



void loop() {
  Serial.begin(9600);

  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;


  if (digitalRead(OUT_PIN) == HIGH) {
    sampleBufferValue++;
  }

  if (millisElapsed > SAMPLE_TIME) {
    Serial.println(sampleBufferValue);
    //Serial.println(val);
    int val2;
    val2 = map(sampleBufferValue, 0, 3, 3, 60);

    if (val2 > val){
      if (val2 > 48){
        val = val + 2;
      } else if (val2 > 30){
        val = val + 3;
      } else{
        val = val + 6;
      }
    }
    if (val2 <  val){
      minn = minn + 1;
      if (val > 48 and minn == 4){
        val = val - 3;
        minn = 0;
      } else if (val > 30 and minn == 5){
        val = val - 2;
        minn = 0;
      } else if (minn == 10){
        val = val - 1;
        minn = 0;
      }
    }
    
    sampleBufferValue = 0;
    millisLast = millisCurrent;
  }
  
  VolumeLevel(val);
    

}

/*
Kleur verdeeling 
Groen:10 Geel:6 Rood:4
Groen: 5/10 Geel: 3/10 Rood: 2/10
*/

void VolumeLevel(int level){
    for (int i = 0; i < level; i++){
        if (i < 30){
            leds[i] = CHSV(100, 255, 255);
        } else if (i < 48){
            leds[i] = CHSV(40, 255, 255);
        } else if (i < 60){
            leds[i] = CHSV(5, 255, 255);
        }
    }
    for (int i = level; i < 60; i++){
      leds[i] = CHSV(0, 0, 0);
    }
    FastLED.show();
}