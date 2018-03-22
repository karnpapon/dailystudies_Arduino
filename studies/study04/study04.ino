// I/O 
int ledPin = 13;
int buttonPin = 4;


// global variables
int toggleState;
int buttonState = 1;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin , INPUT);  
}


void loop() {
  buttonState = digitalRead(buttonPin);

  //  whenever btn is press (== 0) while function is trigged. 
  while(buttonState == 0){
    buttonState = digitalRead(buttonPin);
    toggleState = !toggleState;
    digitalWrite(ledPin, toggleState);
    delay(150);
  }

  toggleState = !toggleState;
  digitalWrite(ledPin, toggleState);
  delay(400);
}
