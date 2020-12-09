#include <DMXSerial.h>
#include <FastLED.h>
#include <EEPROM.h>



//Insteling
//################################
#define DATA_PIN 5
#define Geluidsensor_PIN 8
#define NUM_LEDS 255
//geluide sensor
const int OUT_PIN = 8;
const int SAMPLE_TIME = 20;
//aantal effecten standaardt 6
const int effecten = 6;
//################################


CRGB leds[NUM_LEDS];
//channels definitie
int chl1, chl2, chl3, chl4, chl5, chl6, chl7, chl8;
int chl9, chl10, chl11, chl12, chl13, chl14, chl15, chl16;

int vorigchl6;

unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;
int geluidlevel;
int sampleBuffergeluidlevelue = 0;
int minn;

int timer = 0;
int speed;
uint8_t hue = 0;
// zorgt er voor dat de eeprom maar 1 keer gelezen wordt
bool eeprom_read = false;

//plaatshouders voor funcsies
int plaatshouder1 = 0;

void setup () {
  DMXSerial.init(DMXReceiver);
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);

}

void loop() {
  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  int effectnummer;
  DMXscannen();
  effectnummer = map(chl1, 0, 255, 1, 8);

  // geluid sensor
  if (digitalRead(OUT_PIN) == HIGH) {
    sampleBuffergeluidlevelue++;
  }
  //-------------------------------
  if (millisElapsed > SAMPLE_TIME) {

    // Er word berekend welk level er mag staan bij het efect geluid level
    if (effectnummer == 7) {
      int geluidvoorlopig;
      geluidvoorlopig = map(sampleBuffergeluidlevelue, 0, 20, 3, 60);

      if (geluidvoorlopig > geluidlevel) {
        if (geluidvoorlopig > 48) {
          geluidlevel = geluidlevel + 2;
        } else if (geluidvoorlopig > 30) {
          geluidlevel = geluidlevel + 3;
        } else {
          geluidlevel = geluidlevel + 6;
        }
      }
      if (geluidvoorlopig <  geluidlevel) {
        minn = minn + 1;
        if (geluidlevel > 48 and minn == 4) {
          geluidlevel = geluidlevel - 3;
          minn = 0;
        } else if (geluidlevel > 30 and minn == 5) {
          geluidlevel = geluidlevel - 2;
          minn = 0;
        } else if (minn == 10) {
          geluidlevel = geluidlevel - 1;
          minn = 0;
        }
      }
      VolumeLevel(geluidlevel);
    } else if (chl7 >= 127) { //Laat de effecten rejageren op het geluide

      if (sampleBuffergeluidlevelue > 4) {
        timer += 10000;
      }
    }


    sampleBuffergeluidlevelue = 0;
    millisLast = millisCurrent;
  }


  // Regelt de snelijd van het effect.
  if (chl6 != vorigchl6) {
    speed = map(255 - chl6, 0, 255, -32760, 20000);
    vorigchl6 = chl6;
  }
  if (timer > speed) {

    if (effectnummer == 1) {
      ledsset();
    }
    if (effectnummer == 2) {
      Loopende(0);
    }
    if (effectnummer == 3) {
      Regenboog();
    }
    if (effectnummer == 4) {
      Sterrenhemel();
    }
    if (effectnummer == 5) {
      Stroboscoop();
    }

    timer = -32762;
  }
  timer += 1;

  if ((chl9 > 250) && (chl10 > 250) && (chl11 > 250) && (chl12 > 250)) {
    ProgramerMode();
  }
}

//dient om het effect te onthouden.
void ProgramerMode() {
  unsigned long previousMillis = 0;
  const long intergeluidlevel = 1000;
  bool statusleds = false;
  bool mode = false;

  while (mode == false) {
    if ((chl9 == 0) && (chl10 == 0) && (chl11 == 0) && (chl12 == 0)) {
      mode = true;
    }
    unsigned long currentMillis = millis();
    // knipperen leds rood
    if (currentMillis - previousMillis >= intergeluidlevel) {
      previousMillis = currentMillis;
      if (statusleds == true) {
        for (int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        statusleds = false;
      } else {
        for (int i = 0; i < NUM_LEDS; i++) {
          leds[i] = CRGB(0, 0, 0);
        }
        FastLED.show();
        statusleds = true;
      }
    }
    DMXscannen();
  }

  // slaat de channels op in de EERROM voor wanner er geen dmx is en je toch bepaalde insteling wilt houden.
  EEPROM.write(1, chl1);
  EEPROM.write(2, chl2);
  EEPROM.write(3, chl3);
  EEPROM.write(4, chl4);
  EEPROM.write(5, chl5);
  EEPROM.write(6, chl6);
  EEPROM.write(7, chl7);
  EEPROM.write(8, chl8);

  // hier word bepaalt en opgeslagen welk channels de arduino moet naar luisteren
  if ((chl13 > 250) && (chl14 > 250) && (chl15 > 255)) {
    int channelstart;
    if (chl16 < 17) {
      channelstart = 0;
    } else if (chl16 < 33) {
      channelstart = 16;
    } else if (chl16 < 49) {
      channelstart = 32;
    } else if (chl16 < 65) {
      channelstart = 48;
    } else if (chl16 < 81) {
      channelstart = 64;
    } else if (chl16 < 97) {
      channelstart = 80;
    } else if (chl16 < 113) {
      channelstart = 96;
    } else if (chl16 < 129) {
      channelstart = 112;
    } else if (chl16 < 145) {
      channelstart = 128;
    } else if (chl16 < 161) {
      channelstart = 144;
    } else if (chl16 < 177) {
      channelstart = 160;
    } else if (chl16 < 161) {
      channelstart = 176;
    }
    EEPROM.write(0, channelstart);
  }

  int a;
  while (a < 200)
  {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(255, 0, 0);
    }
    FastLED.show();
    a = a + 1;
  }
}

// scannen alle DMX channels plaatst de data in de gedefinitie channels
void DMXscannen() {
  // Berekent hoe lang het geleden is dat er data is ontvangen op de DMX
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

    chl9 = DMXSerial.read(9);
    chl10 = DMXSerial.read(10);
    chl11 = DMXSerial.read(11);
    chl12 = DMXSerial.read(12);
    chl13 = DMXSerial.read(13);
    chl14 = DMXSerial.read(14);
    chl15 = DMXSerial.read(15);
    chl16 = DMXSerial.read(16);

  } else {
    // Laat zien wanner er geen data ontvangen is langer als 5 seconden.

    //zet de EEPROM geluidlevelues in de juist channels definitie
    if (eeprom_read == false) {
      chl1 = EEPROM.read(1);
      chl2 = EEPROM.read(2);
      chl3 = EEPROM.read(3);
      chl4 = EEPROM.read(4);
      chl5 = EEPROM.read(5);
      chl6 = EEPROM.read(6);
      chl7 = EEPROM.read(7);
      chl8 = EEPROM.read(8);
      eeprom_read = true;
    }
  }

}


// Hier mee kan je de led zelf alle leds naar de kluer verander die jij wilt via de DMX controler.
void ledsset() {
  for (int i = 0; i < chl5; i++) {
    leds[i] = CRGB(chl2, chl3, chl4);
  }
  FastLED.show();
}

// Dit geeft een loopen effect
void Loopende(int level) {
  int middel =  (NUM_LEDS + 1) / 6;
  int plaas = plaatshouder1;
  for (int i = 0; i < middel; i++) {
    for (int i = 0; i < 3; i++) {
      leds[i + plaas] = CRGB(chl2, chl3, chl4);;
    }
    plaas += 3;
    for (int i = 0; i < 3; i++) {
      leds[i + plaas] = CRGB::Black;
    }
    plaas += 3;
  }
  if (plaatshouder1 == 5) {
    plaatshouder1 = 0;
  } else {
    plaatshouder1 += 1;
  }
  FastLED.show();
}

// Dit geeft een mooi regenboog effect
void Regenboog() {
  int Veelvuldig = map(chl3, 0, 255, 0, 100);
  hue = hue + map(chl2, 0, 255, 0, 10);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i * Veelvuldig), 255, 150);
  }
  FastLED.show();
}

// Dit geeft een effect dit er allemal sterren blinken
void Sterrenhemel() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }
  long randNumber;
  for (int i = 0; i < 20; i++) {
    randNumber = random(i * 10, i * 10 + 10);
    leds[randNumber] = CRGB(chl2, chl3, chl4);
  }
  FastLED.show();
}

// Een redelijk standaard Stroboscoop
void Stroboscoop() {
  if (plaatshouder1 == 0) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(chl2, chl3, chl4);
    }
    plaatshouder1 = 1;
  } else {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(0, 0, 0);
    }
    plaatshouder1 = 0;
  }
  FastLED.show();
}

// dit is een geluids meeter zo als je zit op een dj pannel

/*
  Kleur verdeeling
  Groen:10 Geel:6 Rood:4
  Groen: 5/10 Geel: 3/10 Rood: 2/10
*/

void VolumeLevel(int level) {
  for (int i = 0; i < level; i++) {
    if (i < 30) {
      leds[i] = CHSV(100, 255, 255);
    } else if (i < 48) {
      leds[i] = CHSV(40, 255, 255);
    } else if (i < 60) {
      leds[i] = CHSV(5, 255, 255);
    }
  }
  for (int i = level; i < 60; i++) {
    leds[i] = CHSV(0, 0, 0);
  }
  FastLED.show();
}