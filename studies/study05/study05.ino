// pin definitions
int ledPin = 13;
int buttonPin = 4;

// global variables
int toggleState;
int lastButtonState = 1;
long unsigned int lastPress; // "unsigned" datatype not provide memory for negative value, so positive value's allocated memory is doubled, suitable for "time". 
int debounceTime = 20; 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); // INPUT_PULLUP is used whenever resister component is not connected to breadboard.
  Serial.begin(9600);
}

void loop() {  
  int buttonState = digitalRead(buttonPin);  
  Serial.println(buttonState);
  if((millis() - lastPress) > debounceTime)  
  {
    lastPress = millis();   
     
    // NOTE: led is ONLY active when button is not pressed(on the otherword "after release pressing")
    if(buttonState == 0 && lastButtonState == 1){ // this statement is "true"
      toggleState =! toggleState;  // so, toggleState -> 1, because buttonState = 0 (is NOT pressed)
      digitalWrite(ledPin, toggleState); // active led.
      lastButtonState = 0; // flip button's state (preparation for the next "if" statement).
    } //at first execution LED is ON.
    
    // this statement says, when button is pressed,   
    if(buttonState == 1 && lastButtonState == 0){
      lastButtonState = 1;
    }
  }
}
