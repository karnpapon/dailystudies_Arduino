
const int ledPin =  LED_BUILTIN;

int ledState = LOW;            


unsigned long previousMillis = 0;    


const long interval = 1000;      

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  unsigned long currentMillis = millis();
  
  // every 1 sec previousMillis is pushed timestamp eg. (1000ms, 2000ms, 3000ms and so on).
  // default LED is LOW, so when first reach (1000) "if" function will be trigged, LED is set to HIGH
  // next currentMillis (1001) is not match if function so LED is still set to HIGH.
  // currentMillis 2nd reach (2000), "if" function going to be trigged again and set LED to LOW.
  // the iteration is keep repeating itself.
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
  Serial.println(previousMillis);
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
}
