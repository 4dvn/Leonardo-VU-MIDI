const byte _NLED = 16; // How many NeoPixels are attached to the Arduino?
const byte _DPIN = 2; // Which pin on the Arduino is connected to the NeoPixels?

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel _LED = Adafruit_NeoPixel(_NLED, _DPIN, NEO_GRB + NEO_KHZ800);

// this is an array allowing you to set the colour for each neolpixel.
uint32_t colours[32]={150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150};

#include "MIDIUSB.h"

//const byte _PStart = 36;  // First note in array
//bool update = false;

// this process the commands from trakor to turn on a led
void noteOn(byte channel, byte statOn, byte velocity) {
  
    _LED.setPixelColor(statOn,colours[statOn]);  
 
}
// this turns off the leds.
void noteOff(byte channel, byte statOn, byte velocity) {

    _LED.setPixelColor(statOn, 0);  
      
}
void setup() {
// Serial.begin(115200);
  _LED.begin(); // This initializes the NeoPixel library.

 // a simple loop to generate some colors for the neopixels.
  for (int x=0; x < 24; x++){
    colours[x] = _LED.Color(x*6, 145-(x*6), 0);
  }
  for (int x=0; x < 8; x++){
    colours[x+24] = _LED.Color(x*18, 145-(x*18), 0);
  }    
  _LED.setPixelColor(0, colours[0]);
}
void loop() {
    MidiUSB.flush();
    delay(1500); // Delay for a period of time (in milliseconds).
    _LED.show(); // This sends the updated pixel color to the hardware.
     
}
