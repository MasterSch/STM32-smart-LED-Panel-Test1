#include <Arduino.h>

#define Line_A 0
#define Line_B 1
#define Line_C 2
#define Line_D 3

#define clock 4
#define latch 5
#define outen 6

#define red   10
#define green 11
#define blue  12


void setup() {
  // put your setup code here, to run once:

pinMode (Line_A, OUTPUT);
pinMode (Line_B, OUTPUT);
pinMode (Line_C, OUTPUT);
pinMode (Line_D, OUTPUT);

pinMode(clock, OUTPUT);
pinMode(latch, OUTPUT);
pinMode(outen, OUTPUT);

pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);

digitalWrite(Line_A, 0);
digitalWrite(Line_B, 0);
digitalWrite(Line_C, 0);
digitalWrite(Line_D, 0);

digitalWrite(clock, 0);
digitalWrite(latch, 0);
digitalWrite(outen, 0);

digitalWrite(red, 0);
digitalWrite(green, 0);
digitalWrite(blue, 0);




}

void loop() { 
  // put your main code here, to run repeatedly:

byte red1[] = {1, 2, 4, 8, 16, 32, 64, 128, 128, 64, 32, 16, 8, 4, 2, 1};
byte green1[] = {2, 4, 8, 16, 32, 64, 128, 128, 64, 32, 16, 8, 4, 2, 1, 2};
byte blue1[] = {4, 8, 16, 32, 64, 128, 128, 64, 32, 16, 8, 4, 2, 1, 2 ,4};

while(1) {

digitalWrite(clock, 0);
digitalWrite(latch, 0);
digitalWrite(outen, 0);

int x = 0;

do  {

int y = 0;

do  {

if (bitRead(red1[x], y )) digitalWrite(red, 1);
else digitalWrite(red, 0);

if (bitRead(green1[x], y )) digitalWrite(green, 1);
else digitalWrite(green, 0);

if (bitRead(blue1[x], y )) digitalWrite(blue, 1);
else digitalWrite(blue, 0);

digitalWrite(clock, 1);
digitalWrite(clock, 0);

y++;

//delay(100);

} while (y<8);

x++;

} while (x<16);

delayMicroseconds(1);
digitalWrite(latch, 1);
delayMicroseconds(1);
digitalWrite(latch, 0);
delayMicroseconds(1);
digitalWrite(outen, 1);

// delay(1000);

 }  
}