#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redPin = 10;
const int greenPin = 11;
int ledState = LOW;


void setup(){
  irrecv.enableIRIn();
  irrecv.blink13(true); //blink light on Arduino board, useful for debugging
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0xFF38C7: //Keypad button "5"
          if (ledState == LOW){
            ledState = HIGH;
          } else { 
            ledState = LOW;  
            }
            digitalWrite(redPin, ledState);
        }

        irrecv.resume(); // reset receiver, prepare for the next code.
    }
}
