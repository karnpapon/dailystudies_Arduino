int inPin = 2;   // the number of the input pin
int reading;     // the current reading from the input pin
int GreenLedPin = 13;  // the number of the Green LED output pin
int RedLedPin = 12;    // the number of the Red LED output pin
const int SpeakerPin = 11; // the number of the Speaker/Buzzer pin

void setup(){
  pinMode (inPin, INPUT);
  pinMode (GreenLedPin, OUTPUT);
  pinMode (RedLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop () {
  reading = digitalRead(inPin);
  if (reading == 1) {
    digitalWrite(RedLedPin, HIGH);   
    digitalWrite(GreenLedPin, LOW);
    tone(SpeakerPin, 494, 100);  // 2nd argument = freq, 3rd = duration
   delay(50); // minimun is 10
   
  } else {
    digitalWrite(RedLedPin, LOW);
    digitalWrite(GreenLedPin, HIGH);    // if not tilted, turn the green LED ON
  }
  Serial.println(reading); 

  delay(200); 
}


