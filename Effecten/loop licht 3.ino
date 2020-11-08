#include <DMXSerial.h>
#include <FastLED.h>
#define NUM_LEDS 100
CRGB leds[NUM_LEDS];
uint8_t hue = 0;


#define DATA_PIN 5

int chl1;
int chl2;
int chl3;
int chl4;

int chl5;
int chl6;
int chl7;
int chl8;

int timer = 0;

//plaatshouders voor funcsies 
int plaatshouder1;

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

  } 
   if (timer == 32000){
      Middel(0);
      timer = -32000;
  }
  timer += 1;
  

}




void Middel(int level){
    int middel =  (NUM_LEDS + 1) / 6;
    int plaas = plaatshouder1;
    for (int i = 0;i < middel; i++){
        for (int i = 0;i < 3; i++){
            leds[i + plaas] = CRGB(chl2, chl3, chl4);;
        }
        plaas += 3;
        for (int i = 0;i < 3; i++){
            leds[i + plaas] = CRGB::Black;
        }
        plaas += 3;
    }
    if (plaatshouder1 == 5){
        plaatshouder1 = 0;
    } else {
        plaatshouder1 += 1;
    }
    FastLED.show();
}