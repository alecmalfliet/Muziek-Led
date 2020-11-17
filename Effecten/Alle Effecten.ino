
// Hier mee kan je de led zelf alle leds naar de kluer verander die jij wilt via de DMX controler.
void ledsset(){
    for (int i = 0;i < chl5; i++){
        leds[i] = CRGB(chl2, chl3, chl4);
    }
    FastLED.show();
}

// Dit geeft een loopen effect 
void Loopende(int level){
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

// Dit geeft een mooi regenboog effect 
void Regenboog(){
  int Veelvuldig = map(chl3, 0, 255, 0, 100);
  hue = hue + map(chl2, 0, 255, 0, 10);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i * Veelvuldig), 255, 150);
  }
  FastLED.show();
}

// Dit geeft een effect dit er allemal sterren blinken
void Sterrenhemel(){
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

// Een redelijk standaard Stroboscoop
void Stroboscoop(int speed){
    if (plaatshouder1 == 0){
        for (int i = 0;i < NUM_LEDS; i++){
            leds[i] = CRGB(chl2, chl3, chl4);
        }
        plaatshouder1 = 1;
    } else {
        for (int i = 0;i < NUM_LEDS; i++){
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