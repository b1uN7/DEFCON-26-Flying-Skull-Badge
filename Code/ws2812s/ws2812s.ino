#include <Adafruit_NeoPixel.h>
#define PIN 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  //slowChase(3000);
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  strip.show(); // Initialize all pixels to 'off'
  delay(2000);
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  strip.show(); // Initialize all pixels to 'off'
  delay(2000);
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  strip.show(); // Initialize all pixels to 'off'
  delay(2000);

  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  strip.show(); // Initialize all pixels to 'off'
  delay(2000);
  theaterChase(strip.Color(127, 0, 0), 50); // Red
  strip.show(); // Initialize all pixels to 'off'
  delay(2000);
  theaterChase(strip.Color(0, 0, 127), 50); // Blue
  strip.show(); // Initialize all pixels to 'off'
  delay(2000);

  rainbow(20);
  strip.show(); // Initialize all pixels to 'off'
  delay(2000);
  rainbowCycle(20);
  strip.show(); // Initialize all pixels to 'off'
  delay(2000);
  theaterChaseRainbow(50);
  strip.show(); // Initialize all pixels to 'off'
  delay(2000);

  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void slowChase(uint8_t wait) {
  uint16_t i;

  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i-3, 0,0,0);
    strip.setPixelColor(i-2, 127,127,127);
    strip.setPixelColor(i-1, 127, 127, 127);
    strip.setPixelColor(i, 0,0,255);
    strip.show();

    delay(500);
  }
  strip.show();
  delay(wait);
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
