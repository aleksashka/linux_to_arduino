#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 3
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
int delayval = 500; // delay for half a second
int stage;
uint8_t mesType,mesLen,i;
//uint8_t inData[];

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
  stage = 0;  //0 - type should be received, 1 - length, 2 - values
}

void loop() {
  if (Serial.available()) {
    if (stage == 0) {
      Serial.println("");
      mesType = Serial.read();
      stage = 1;
      Serial.print("Stage: 0->1, mesType: ");Serial.println(mesType);
    } else if (stage == 1) { 
      mesLen = Serial.read();
      stage = 2;
      Serial.print("Stage: 1->2, mesLen: ");Serial.println(mesLen);
    } else if (stage == 2) {
      uint8_t inData[mesLen];
      i = 0;
      while (Serial.available() and (i<mesLen)) {
        inData[i] = Serial.read();
        Serial.print("Stage: 2, inData[");Serial.print(i);Serial.print("]: ");Serial.println(inData[i]);
        i++;
      }
      stage = 0;
      Serial.print("Stage: ");Serial.println(stage);
      if (i == mesLen) {
        if ( mesType == 0 ) {
          setPix(inData[0], pixels.Color(0,0,0));
        } else if ( mesType == 1 ) {
          setPix(inData[0], pixels.Color(inData[1],inData[2],inData[3]));
        }
        //showWeather(inData[0], pixels.Color(inData[1],inData[2],inData[3]), delayval);
      } else {
        Serial.println("Transaction is bad");
      }
    }
    
    
    
    //message = Serial.readString();
    //incomingByte = Serial.read();
    //showWeather(0, pixels.Color(incomingByte,0,0), delayval);
//    if ( incomingByte == 0xFF ) {
//      showWeather(0, pixels.Color(50,0,0), delayval);
//    } else if ( incomingByte == 0xEE ) {
//      showWeather(0, pixels.Color(0,50,0), delayval);
//    }
    //Serial.print("I received: ");
    //Serial.print(incomingByte, HEX);
  }
  //ard.flushInput();
  //showWeather(0, pixels.Color(50,0,0), delayval);
  //showWeather(0, pixels.Color(0,50,0), delayval);
  //showWeather(0, pixels.Color(0,0,50), delayval);
  //delay(delayval*5); // Delay for a period of time (in milliseconds).
}

void setPix(int pix, uint32_t c) {
  pixels.setPixelColor(pix, c);
  pixels.show();
}

void showWeather(int pix, uint32_t c, uint16_t wait) {
  pixels.setPixelColor(pix, c);
  pixels.show();
  delay(wait);
  pixels.setPixelColor(pix, pixels.Color(0,0,0));
  pixels.show();
  delay(wait);
}

