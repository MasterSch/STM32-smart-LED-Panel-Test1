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

//byte red1[] = {1, 2, 4, 8, 16, 32, 64, 128, 128, 64, 32, 16, 8, 4, 2, 1};
//byte green1[] = {2, 4, 8, 16, 32, 64, 128, 128, 64, 32, 16, 8, 4, 2, 1, 2};
//byte blue1[] = {4, 8, 16, 32, 64, 128, 128, 64, 32, 16, 8, 4, 2, 1, 2 ,4};

byte red1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte green1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte blue1[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128};


while(1) {

digitalWrite(clock, 0);
digitalWrite(latch, 0);
digitalWrite(outen, 1);

int z = 0;

do {

if ((z & 0x01) == false) digitalWrite(Line_A, 0);
else digitalWrite(Line_A, 1);

if ((z & 0x02) == false) digitalWrite(Line_B, 0);
else digitalWrite(Line_B, 1);

if ((z & 0x04) == false) digitalWrite(Line_C, 0);
else digitalWrite(Line_C, 1);

if ((z & 0x08) == false) digitalWrite(Line_D, 0);
else digitalWrite(Line_D, 1);  

delay(1);

int x = 0;

do  {

int y = 1;

do  {

if ((red1[x] & y ) == false) digitalWrite(red, 0);
else digitalWrite(red, 1);

if ((green1[x] & y ) == false) digitalWrite(green, 0);
else digitalWrite(green, 1);

if ((blue1[x] & y ) == false) digitalWrite(blue, 0);
else digitalWrite(blue, 1);


digitalWrite(clock, 1);
digitalWrite(clock, 0);

y = y << 1;

} while (y < 32768);   // 8 Bits

x++;

} while (x<8); // 1 Zeile

digitalWrite(outen, 1);
delayMicroseconds(10);
digitalWrite(latch, 1);
delayMicroseconds(10);
digitalWrite(outen, 0);
delayMicroseconds(10);
digitalWrite(latch, 0);

delay(1000);

z++;

} while (z < 16);


 }  
}