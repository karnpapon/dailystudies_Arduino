const int dataPin = 6;
const int clockPin = 7;
const int latchPin = 8;
byte ledMap = 0b11111111;
int delayTime = 3000;
void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  
  Serial.begin(9600);
  shiftWrite(0x00);
  Serial.println("Enter a number between 0-255");
}
void loop() {
  if(Serial.available())
  {
    int inputVal = Serial.parseInt();
    
    if(inputVal > 255)
    {
      Serial.println("Uh oh, try again");
      Serial.println("Enter a number between 0-255"); 
      return;
    }
    Serial.println(ledMap, BIN);
    Serial.print("DECIMAL: ");
    Serial.println(inputVal);
    Serial.print("BINARY: ");
    Serial.println(inputVal, BIN);
    Serial.println();

    // align right before operation.
    // ex.BIN = 11111111;
    // 10 BIN =     1010;
    // AND    = 00001010; 
    Serial.print("AND result: "); // AND = have both.
    Serial.println(ledMap & inputVal, BIN);
    shiftWrite(ledMap & inputVal);
    delay(delayTime);

    
    // align right before operation.
    // ex.BIN = 11111111;
    // 10 BIN =     1010;
    // OR     = 11111111; 
    Serial.print("OR  result: "); // OR = have either.
    Serial.println(ledMap | inputVal, BIN);
    shiftWrite(ledMap | inputVal);
    delay(delayTime);


    // align right before operation.
    // ex.BIN = 11111111;
    // 10 BIN =     1010;
    // XOR    = 11110101;     
    Serial.print("XOR result: "); // XOR = have either and NOT both.
    Serial.println(ledMap ^ inputVal, BIN);
    shiftWrite(ledMap ^ inputVal);
    delay(delayTime);
    Serial.println();
    Serial.println("Enter a number between 0-255");
  }  
}
void shiftWrite(byte value)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}
