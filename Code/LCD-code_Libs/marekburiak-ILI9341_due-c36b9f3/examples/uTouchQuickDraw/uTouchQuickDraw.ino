#include <SPI.h>
#include <ILI9341_due_config.h>
#include <ILI9341_due.h>

#include <URTouch.h>

// For the Adafruit shield, these are the default.
#define TFT_RST 8
#define TFT_DC 9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
ILI9341_due tft = ILI9341_due(TFT_CS, TFT_DC, TFT_RST);

URTouch  myTouch(15, 7, 14, 16, 6);  //URTouch(byte tclk, byte tcs, byte din, byte dout, byte irq)
int x, y, px, py;


void setup()
{
	tft.begin();
  Serial.begin(9600);
  while (!Serial) ; // wait for Arduino Serial Monitor
  Serial.println(F("ILI9341 Touch Test!")); 

	tft.setRotation(iliRotation270);	// landscape
	tft.fillScreen(ILI9341_BLUE);
	
	myTouch.InitTouch();
	myTouch.setPrecision(PREC_MEDIUM);
}

void loop()
{
	long x, y;

	while (myTouch.dataAvailable() == true)
	{
		myTouch.read();
		x = myTouch.getX();
		y = myTouch.getY();
		if ((x != -1) && (y != -1))
		{
			tft.drawPixel(x, y, ILI9341_WHITE);
      Serial.print("X= ");
      Serial.print(x);
      Serial.print("\tY=");
      Serial.println(y);
      delay(500);

		}
	}
}
