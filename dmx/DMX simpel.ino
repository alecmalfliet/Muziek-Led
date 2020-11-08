#include <DMXSerial.h>

int ch1;

void setup () {
  DMXSerial.init(DMXReceiver); 
}

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();
  if (lastPacket < 5000) {
    ch1 = DMXSerial.read(1);

  } else {
      // als er geen DMX aan wezig is
  }
}
