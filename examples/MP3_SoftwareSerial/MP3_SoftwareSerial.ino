/*******************************************************
arduino pin 3 -> 4.7k resistor -> 10k resistor -> ground
                               |
                               |-> mp3 rx
arduino pin 2 -> mp3 tx
5v -> mp3 vcc
gnd -> mp3 gnd
*******************************************************/

#include <MP3_Module.h>
#include <SoftwareSerial.h>

const int buttonPin[] = { 8, 9, 10 };

MP3 mp3;

void setup() {
  for(int i = 0; i < 3; i++){
    pinMode(buttonPin[i], INPUT_PULLUP);
  }
  
  mp3.begin(); // initialize mp3
  mp3.volume(30); // set max volume
  mp3.play(); // play
  
  // uncomment below to select specific file to play
  //mp3.select_file(1); // select file 1
}

void loop() {
  if(digitalRead(buttonPin[0]) == LOW){
    mp3.volume_up();
  }else if(digitalRead(buttonPin[1]) == LOW){
    mp3.volume_down();
  }else if(digitalRead(buttonPin[2]) == LOW){
    mp3.next();
  }
}
