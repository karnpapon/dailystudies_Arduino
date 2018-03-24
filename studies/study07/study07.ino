
const int  buttonPin = 2;    
const int ledPin = 13;   

int buttonPushCounter = 0;
int buttonState = 0;      
int lastButtonState = 0;  

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  buttonState = digitalRead(buttonPin);
  
  //  "if" is not actived at first executes, because buttonState == lastButtonState ( 0 == 0 )
  //  then, when button is pressed buttonState = 1, if statement is actived.
  //  also buttonState == 1, thus 1 = HIGH, another if statement is actived.
  //  after button is released "else" statement is actived.
  //  delay(50) prevent bouncing.
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      Serial.println("off");
    }
    delay(50);
  }
  lastButtonState = buttonState;  //store lastButtonState for next iterations.

  // led is modulo 4, so it's only HIGH every 4 times pressing.
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
