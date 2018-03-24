//Title : 4-Digits Display

/*
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D

 */
 
int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 500;

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int pinDot = 13;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;


void setup() {                
  
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);
  pinMode(pinDot, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
}

void loop() {

  unsigned long currentMillis = millis();

  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);   

  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    if (ledState == LOW){
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }
  digitalWrite(pinDot, ledState);  

}
