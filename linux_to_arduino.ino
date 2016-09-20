#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 3
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
int delayval = 500; // delay for half a second
int incomingByte;
String message;

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
}

void loop() {
  if (Serial.available() > 0) {
    //message = Serial.readString();
    incomingByte = Serial.read();
    if ( incomingByte == '1' ) {
      showWeather(0, pixels.Color(50,0,0), delayval);
    } else if ( incomingByte == '2' ) {
      showWeather(0, pixels.Color(0,50,0), delayval);
    }
    Serial.print("I received: ");
    Serial.println(incomingByte);
  }
  //showWeather(0, pixels.Color(50,0,0), delayval);
  //showWeather(0, pixels.Color(0,50,0), delayval);
  //showWeather(0, pixels.Color(0,0,50), delayval);
  //delay(delayval*5); // Delay for a period of time (in milliseconds).
}

void showWeather(int pix, uint32_t c, uint16_t wait) {
  pixels.setPixelColor(pix, c);
  pixels.show();
  delay(wait);
  pixels.setPixelColor(pix, pixels.Color(0,0,0));
  pixels.show();
  delay(wait);
}


