/*
Just a first test for a password generator. NOT secure and not, yet, meant to be

This genrates, at a button (pin 0) press, a 12 chartacter password composed of 
alphanumerical charatcters.
For it to generate a character it reads the analogue pin 1 for nosie and then 
it pseudo-randomely selects a character. After selecting and outputting a 
charcater it waits the integer value of the ascii character in milliseconds to,
hopefully, read a different noise.

Further iterations will have a noise generator to attach to pin 1.


QUICK SCHEMATIC

                           __   __
                           |1'-'8|----- VCC
                   TX -----|2   7|                VCC
                   RX -----|3   6|                 |
                  GND -----|4___5|--------------button

CasteSoftworks 2023/12

V1    -    18/12/23   -   First Commit

*/

#include <SoftwareSerial.h>
#define BOTTONE 0
#define CASO 1

SoftwareSerial Serial(3,4);

long rNum;
int buttonState;
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BOTTONE,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState=digitalRead(BOTTONE);
  if (buttonState==1){
      for(i=0;i<12;i++){
        randomSeed(analogRead(CASO));
        rNum=random(32,127);
        Serial.print(char(rNum));
        delay(rNum);
      }
      delay(1000);
      Serial.println();
    }
  }
