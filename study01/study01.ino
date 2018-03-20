
// controll LED by Potentionmeter.


int led = 9;
int brightness = 0;

void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT);
}


void loop() {
  
  int sensorValue = analogRead(A0);
  //map sensorValue from 0 - 1023 to 0 - 255 suitable for LED value.
  sensorValue = map(sensorValue, 0, 1023, 0, 255);
  Serial.println(sensorValue);
  delay(1); 

  //LED output
  analogWrite(led, sensorValue);
}
