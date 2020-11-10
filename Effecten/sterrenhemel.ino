#include <DMXSerial.h>
#include <FastLED.h>
#define NUM_LEDS 255
CRGB leds[NUM_LEDS];
uint8_t hue = 0;


#define DATA_PIN 5

int chl1;
int chl2;
int chl3;
int chl4;

int chl5;
int chl6;
int vorigchl6;
int chl7;
int chl8;

int timer = 0;
int speed;

//plaatshouders voor funcsies 
int plaatshouder1 = 0;

void setup () {
  DMXSerial.init(DMXReceiver);
  

  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);

}



void loop() {
  // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  
  if (lastPacket < 5000) {

    chl1 = DMXSerial.read(1);
    chl2 = DMXSerial.read(2);
    chl3 = DMXSerial.read(3);
    chl4 = DMXSerial.read(4);
    
    chl5 = DMXSerial.read(5);
    chl6 = DMXSerial.read(6);
    chl7 = DMXSerial.read(7);
    chl8 = DMXSerial.read(8);



  } else {
    // Show when no data was received since 5 seconds or more.
    chl2 = 255;
    chl3 = 255;
    chl4 = 255;
  }
  if (chl6 != vorigchl6){
      speed = map(255 - chl6, 0, 255, -32760, 32760);
      vorigchl6 = chl6;
  }
  if (timer > speed){
      Sterrenhemel(0);
      timer = -32762;
  }
  timer += 1;
}

void Sterrenhemel(int speed){

    for (int i = 0;i < NUM_LEDS; i++){
            leds[i] = CRGB(0, 0, 0);
    }

    long randNumber;
    for (int i = 0;i < 20; i++){
        randNumber = random(i * 10, i * 10 + 10);
        leds[randNumber] = CRGB(chl2, chl3, chl4);
    }
    FastLED.show();
}