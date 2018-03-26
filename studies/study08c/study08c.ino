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

//this is a list of long variables used in this clock program
long s = 0;
long sec = 0;
long hrs = 0;
long minutes = 0;
long initialHours = 21;//variable to initiate hours
long initialMins = 6;//variable to initiate minutes
long initialSecs = 59;//variable to initiate seconds

//Pin 2-8 are the display segments
long pinA = 2;
long pinB = 3;
long pinC = 4;
long pinD = 5;
long pinE = 6;
long pinF = 7;
long pinG = 8;

//Pin 9-12 are the commons for the display. They control which digit is being written to.
long C1 = 9;
long C2 = 10;
long C3 = 11;
long C4 = 12;

//first loop variable
boolean start = true;

/*These methods were written by alex barbosa
   https://gist.github.com/alexbarbosa/5416290
*/

//this method is for seconds
long seconds()
{
  s = initialHours * 3600;
  s = s + (initialMins * 60);
  s = s + initialSecs;
  s = s + (millis() / 1000);
  return s;
}

//this method is for hours
long hours()
{
  hrs = seconds();
  hrs = hrs / 3600;
  hrs = hrs % 24;
  return hrs;
}

//this method is for minutes
long mins()
{
  minutes = seconds();
  minutes = minutes / 60;
  minutes = minutes % 60;
  return minutes;
}

long secs()
{
  sec = seconds();
  sec = sec % 60;
  return sec;
}
void setup() {
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //if (start == true) {
  //  hello();
  //}
  //start = false;
  
  //seconds();
  hours();
  mins();
  secs();
  
  printHours(hrs);
  printMinutes(minutes);

  if((int)secs % 2 == 0){
    Serial.println(sec);
    Serial.println(minutes);
    Serial.println(hrs);
  }
}
//------------------------------//
//numbers 0-9//

#define SEGMENT_ON  HIGH
#define SEGMENT_OFF LOW

void print1() {//prints to digit 1 on display
  delay(1);
  digitalWrite(C1, SEGMENT_ON);
  digitalWrite(C2, SEGMENT_OFF);
  digitalWrite(C3, SEGMENT_OFF);
  digitalWrite(C4, SEGMENT_OFF);
}

void print2() {//prints to digit 2 on display
  delay(1);
  digitalWrite(C1, SEGMENT_OFF);
  digitalWrite(C2, SEGMENT_ON);
  digitalWrite(C3, SEGMENT_OFF);
  digitalWrite(C4, SEGMENT_OFF);
}
void print3() {//prints to digit 3 on display
  delay(1);
  digitalWrite(C1, SEGMENT_OFF);
  digitalWrite(C2, SEGMENT_OFF);
  digitalWrite(C3, SEGMENT_ON);
  digitalWrite(C4, SEGMENT_OFF);
}

void print4() {//prints to digit 4 on display
  delay(1);
  digitalWrite(C1, SEGMENT_OFF);
  digitalWrite(C2, SEGMENT_OFF);
  digitalWrite(C3, SEGMENT_OFF);
  digitalWrite(C4, SEGMENT_ON);
}


void zero() {
  //prints zero
  digitalWrite(pinA, SEGMENT_OFF);
  digitalWrite(pinB, SEGMENT_OFF);
  digitalWrite(pinC, SEGMENT_OFF);
  digitalWrite(pinD, SEGMENT_OFF);
  digitalWrite(pinE, SEGMENT_OFF);
  digitalWrite(pinF, SEGMENT_OFF);
  digitalWrite(pinG, SEGMENT_ON);
}

void one() {
  //prints one
  digitalWrite(pinA, SEGMENT_ON);
  digitalWrite(pinB, SEGMENT_OFF);
  digitalWrite(pinC, SEGMENT_OFF);
  digitalWrite(pinD, SEGMENT_ON);
  digitalWrite(pinE, SEGMENT_ON);
  digitalWrite(pinF, SEGMENT_ON);
  digitalWrite(pinG, SEGMENT_ON);
}

void two() {
  //prints two
  digitalWrite(pinA, SEGMENT_OFF);
  digitalWrite(pinB, SEGMENT_OFF);
  digitalWrite(pinC, SEGMENT_ON);
  digitalWrite(pinD, SEGMENT_OFF);
  digitalWrite(pinE, SEGMENT_OFF);
  digitalWrite(pinF, SEGMENT_ON);
  digitalWrite(pinG, SEGMENT_OFF);
}

void three() {
  //prints three
  digitalWrite(pinA, SEGMENT_OFF);
  digitalWrite(pinB, SEGMENT_OFF);
  digitalWrite(pinC, SEGMENT_OFF);
  digitalWrite(pinD, SEGMENT_OFF);
  digitalWrite(pinE, SEGMENT_ON);
  digitalWrite(pinF, SEGMENT_ON);
  digitalWrite(pinG, SEGMENT_OFF);
}


void four() {
  //prints four
  digitalWrite(pinA, SEGMENT_ON);
  digitalWrite(pinB, SEGMENT_OFF);
  digitalWrite(pinC, SEGMENT_OFF);
  digitalWrite(pinD, SEGMENT_ON);
  digitalWrite(pinE, SEGMENT_ON);
  digitalWrite(pinF, SEGMENT_OFF);
  digitalWrite(pinG, SEGMENT_OFF);
}

void five() {
  //prints five
  digitalWrite(pinA, SEGMENT_OFF);
  digitalWrite(pinB, SEGMENT_ON);
  digitalWrite(pinC, SEGMENT_OFF);
  digitalWrite(pinD, SEGMENT_OFF);
  digitalWrite(pinE, SEGMENT_ON);
  digitalWrite(pinF, SEGMENT_OFF);
  digitalWrite(pinG, SEGMENT_OFF);
}

void six() {
  //prints six
  digitalWrite(pinA, SEGMENT_OFF);
  digitalWrite(pinB, SEGMENT_ON);
  digitalWrite(pinC, SEGMENT_OFF);
  digitalWrite(pinD, SEGMENT_OFF);
  digitalWrite(pinE, SEGMENT_OFF);
  digitalWrite(pinF, SEGMENT_OFF);
  digitalWrite(pinG, SEGMENT_OFF);
}

void seven() {
  //prints seven
  digitalWrite(pinA, SEGMENT_OFF);
  digitalWrite(pinB, SEGMENT_OFF);
  digitalWrite(pinC, SEGMENT_OFF);
  digitalWrite(pinD, SEGMENT_ON);
  digitalWrite(pinE, SEGMENT_ON);
  digitalWrite(pinF, SEGMENT_ON);
  digitalWrite(pinG, SEGMENT_ON);
}

void eight() {
  //prints eight
  digitalWrite(pinA, SEGMENT_OFF);
  digitalWrite(pinB, SEGMENT_OFF);
  digitalWrite(pinC, SEGMENT_OFF);
  digitalWrite(pinD, SEGMENT_OFF);
  digitalWrite(pinE, SEGMENT_OFF);
  digitalWrite(pinF, SEGMENT_OFF);
  digitalWrite(pinG, SEGMENT_OFF);
}

void nine() {
  //prints nine
  digitalWrite(pinA, SEGMENT_OFF);
  digitalWrite(pinB, SEGMENT_OFF);
  digitalWrite(pinC, SEGMENT_OFF);
  digitalWrite(pinD, SEGMENT_OFF);
  digitalWrite(pinE, SEGMENT_ON);
  digitalWrite(pinF, SEGMENT_OFF);
  digitalWrite(pinG, SEGMENT_OFF);
}



//------------------------------//
//display minutes functions//
void printMinutes(long m){
  zerozero(m);
  zone(m);
  ztwo(m);
  zthree(m);
  zfour(m);
  zfive(m);
  zsix(m);
  zseven(m);
  zeight(m);
  znine(m);
  ten(m);
  eleven(m);
  twelve(m);
  thirteen(m);
  fourteen(m);
  fifteen(m);
  sixteen(m);
  seventeen(m);
  eighteen(m);
  nineteen(m);
  twenty(m);
  twentyone(m);
  twentytwo(m);
  twentythree(m);
  twentyfour(m);
  twentyfive(m);
  twentysix(m);
  twentyseven(m);
  twentyeight(m);
  twentynine(m);
  thirty(m);
  thirtyone(m);
  thirtytwo(m);
  thirtythree(m);
  thirtyfour(m);
  thirtyfive(m);
  thirtysix(m);
  thirtyseven(m);
  thirtyeight(m);
  thirtynine(m);
  fourty(m);
  fourtyone(m);
  fourtytwo(m);
  fourtythree(m);
  fourtyfour(m);
  fourtyfive(m);
  fourtysix(m);
  fourtyseven(m);
  fourtyeight(m);
  fourtynine(m);
  fifty(m);
  fiftyone(m);
  fiftytwo(m);
  fiftythree(m);
  fiftyfour(m);
  fiftyfive(m);
  fiftysix(m);
  fiftyseven(m);
  fiftyeight(m);
  fiftynine(m);
}

void zerozero(long m){
  if ((m == 0) || (m == 60)) {
    print3();
    zero();
    print4();
    zero();
  }
}

void zone(long m){
  if (m == 1) {
    print3();
    zero();
    print4();
    one();
  }
}

void ztwo(long m){
  if (m == 2) {
    print3();
    zero();
    print4();
    two();
  }
}

void zthree(long m){
  if (m == 3) {
    print3();
    zero();
    print4();
    three();
  }
}

void zfour(long m){
  if (m == 4) {
    print3();
    zero();
    print4();
    four();
  }
}

void zfive(long m){
  if (m == 5) {
    print3();
    zero();
    print4();
    five();
  }
}

void zsix(long m){
  if (m == 6) {
    print3();
    zero();
    print4();
    six();
  }
}

void zseven(long m){
  if (m == 7) {
    print3();
    zero();
    print4();
    seven();
  }
}

void zeight(long m){
  if (m == 8) {
    print3();
    zero();
    print4();
    eight();
  }
}

void znine(long m){
  if (m == 9) {
    print3();
    zero();
    print4();
    nine();
  }
}

void ten(long m){
  if (m == 10) {
    print3();
    one();
    print4();
    zero();
  }
}

void eleven(long m){
  if (m == 11) {
    print3();
    one();
    print4();
    one();
  }
}

void twelve(long m){
  if (m == 12) {
    print3();
    one();
    print4();
    two();
  }
}

void thirteen(long m){
  if (m == 13) {
    print3();
    one();
    print4();
    three();
  }
}

void fourteen(long m){
  if (m == 14) {
    print3();
    one();
    print4();
    four();
  }
}

void fifteen(long m){
  if (m == 15) {
    print3();
    one();
    print4();
    five();
  }
}

void sixteen(long m){
  if (m == 16) {
    print3();
    one();
    print4();
    six();
  }
}

void seventeen(long m){
  if (m == 17) {
    print3();
    one();
    print4();
    seven();
  }
}


void eighteen(long m){
  if (m == 18) {
    print3();
    one();
    print4();
    eight();
  }
}

void nineteen(long m){
  if (m == 19) {
    print3();
    one();
    print4();
    nine();
  }
}

void twenty(long m){
  if (m == 20) {
    print3();
    two();
    print4();
    zero();
  }
}

void twentyone(long m){
  if (m == 21) {
    print3();
    two();
    print4();
    one();
  }
}

void twentytwo(long m){
  if (m == 22) {
    print3();
    two();
    print4();
    two();
  }
}

void twentythree(long m){
  if (m == 23) {
    print3();
    two();
    print4();
    three();
  }
}

void twentyfour(long m){
  if (m == 24) {
    print3();
    two();
    print4();
    four();
  }
}

void twentyfive(long m){
  if (m == 25) {
    print3();
    two();
    print4();
    five();
  }
}

void twentysix(long m){
  if (m == 26) {
    print3();
    two();
    print4();
    six();
  }
}

void twentyseven(long m){
  if (m == 27) {
    print3();
    two();
    print4();
    seven();
  }
}

void twentyeight(long m){
  if (m == 28) {
    print3();
    two();
    print4();
    eight();
  }
}

void twentynine(long m){
  if (m == 29) {
    print3();
    two();
    print4();
    nine();
  }
}

void thirty(long m){
  if (m == 30) {
    print3();
    three();
    print4();
    zero();
  }
}

void thirtyone(long m){
  if (m == 31) {
    print3();
    three();
    print4();
    one();
  }
}

void thirtytwo(long m){
  if (m == 32) {
    print3();
    three();
    print4();
    two();
  }
}

void thirtythree(long m){
  if (m == 33) {
    print3();
    three();
    print4();
    three();
  }
}

void thirtyfour(long m){
  if (m == 34) {
    print3();
    three();
    print4();
    four();
  }
}

void thirtyfive(long m){
  if (m == 30) {
    print3();
    three();
    print4();
    five();
  }
}

void thirtysix(long m){
  if (m == 36) {
    print3();
    three();
    print4();
    six();
  }
}

void thirtyseven(long m){
  if (m == 37) {
    print3();
    three();
    print4();
    seven();
  }
}

void thirtyeight(long m){
  if (m == 38) {
    print3();
    three();
    print4();
    eight();
  }
}

void thirtynine(long m){
  if (m == 39) {
    print3();
    three();
    print4();
    nine();
  }
}

void fourty(long m){
  if (m == 40) {
    print3();
    four();
    print4();
    zero();
  }
}

void fourtyone(long m){
  if (m == 41) {
    print3();
    four();
    print4();
    one();
  }
}

void fourtytwo(long m){
  if (m == 42) {
    print3();
    four();
    print4();
    two();
  }
}

void fourtythree(long m){
  if (m == 43) {
    print3();
    four();
    print4();
    three();
  }
}

void fourtyfour(long m){
  if (m == 44) {
    print3();
    four();
    print4();
    four();
  }
}

void fourtyfive(long m){
  if (m == 45) {
    print3();
    four();
    print4();
    five();
  }
}

void fourtysix(long m){
  if (m == 46) {
    print3();
    four();
    print4();
    six();
  }
}

void fourtyseven(long m){
  if (m == 47) {
    print3();
    four();
    print4();
    seven();
  }
}

void fourtyeight(long m){
  if (m == 48) {
    print3();
    four();
    print4();
    eight();
  }
}

void fourtynine(long m){
  if (m == 49) {
    print3();
    four();
    print4();
    nine();
  }
}

void fifty(long m){
  if (m == 50) {
    print3();
    five();
    print4();
    zero();
  }
}

void fiftyone(long m){
  if (m == 51) {
    print3();
    five();
    print4();
    one();
  }
}

void fiftytwo(long m){
  if (m == 52) {
    print3();
    five();
    print4();
    two();
  }
}

void fiftythree(long m){
  if (m == 53) {
    print3();
    five();
    print4();
    three();
  }
}

void fiftyfour(long m){
  if (m == 54) {
    print3();
    five();
    print4();
    four();
  }
}

void fiftyfive(long m){
  if (m == 55) {
    print3();
    five();
    print4();
    five();
  }
}

void fiftysix(long m){
  if (m == 56) {
    print3();
    five();
    print4();
    six();
  }
}

void fiftyseven(long m){
  if (m == 57) {
    print3();
    five();
    print4();
    seven();
  }
}

void fiftyeight(long m){
  if (m == 58) {
    print3();
    five();
    print4();
    eight();
  }
}

void fiftynine(long m){
  if (m == 59) {
    print3();
    five();
    print4();
    nine();
  }
}

//---------------------//
//display hours functions//
void printHours(long h){
  zerozerozero(h);
  zeroone(h);
  zerotwo(h);
  zerothree(h);
  zerofour(h);
  zerofive(h);
  zerosix(h);
  zeroseven(h);
  zeroeight(h);
  zeronine(h);
  zeroten(h);
  zeroeleven(h);
  zerotwelve(h);
  zerothirteen(h);
  zerofourteen(h);
  zerofifteen(h);
  zerosixteen(h);
  zeroseventeen(h);
  zeroeighteen(h);
  zeronineteen(h);
  zerotwenty(h);
  zerotwentyone(h);
  zerotwentytwo(h);
  zerotwentythree(h);
}

void zerozerozero(long h){
  if((h == 0) || (h == 24)){
    print1();
    zero();
    print2();
    zero();
    
  }
}

void zeroone(long h){
  if(h == 1){
    print1();
    zero();
    print2();
    one();
    
  }
}

void zerotwo(long h){
  if(h == 2){
    print1();
    zero();
    print2();
    two();
    
  }
}

void zerothree(long h){
  if(h == 3){
    print1();
    zero();
    print2();
    three();
    
  }
}

void zerofour(long h){
  if(h == 4){
    print1();
    zero();
    print2();
    four();
    
  }
}

void zerofive(long h){
  if(h == 5){
    print1();
    zero();
    print2();
    five();
    
  }
}

void zerosix(long h){
  if(h == 6){
    print1();
    zero();
    print2();
    six();
    
  }
}

void zeroseven(long h){
  if(h == 7){
    print1();
    zero();
    print2();
    seven();
    
  }
}

void zeroeight(long h){
  if(h == 8){
    print1();
    zero();
    print2();
    eight();
    
  }
}

void zeronine(long h){
  if(h == 9){
    print1();
    zero();
    print2();
    nine();
    
  }
}

void zeroten(long h){
  if(h == 10){
    print1();
    one();
    print2();
    zero();
    
  }
}

void zeroeleven(long h){
  if(h == 11){
    print1();
    one();
    print2();
    one();
    
  }
}

void zerotwelve(long h){
  if(h == 12){
    print1();
    one();
    print2();
    two();
    
  }
}

void zerothirteen(long h){
  if(h == 13){
    print1();
    one();
    print2();
    three();
    
  }
}

void zerofourteen(long h){
  if(h == 14){
    print1();
    one();
    print2();
    four();
    
  }
}

void zerofifteen(long h){
  if(h == 1){
    print1();
    one();
    print2();
    five();
    
  }
}

void zerosixteen(long h){
  if(h == 16){
    print1();
    one();
    print2();
    six();
    
  }
}

void zeroseventeen(long h){
  if(h == 17){
    print1();
    one();
    print2();
    seven();
    
  }
}

void zeroeighteen(long h){
  if(h == 18){
    print1();
    one();
    print2();
    eight();
    
  }
}

void zeronineteen(long h){
  if(h == 19){
    print1();
    one();
    print2();
    nine();
    
  }
}


void zerotwenty(long h){
  if(h == 20){
    print1();
    two();
    print2();
    zero();
    
  }
}


void zerotwentyone(long h){
  if(h == 21){
    print1();
    two();
    print2();
    one();
    
  }
}


void zerotwentytwo(long h){
  if(h == 22){
    print1();
    two();
    print2();
    two();
    
  }
}

void zerotwentythree(long h){
  if(h == 23){
    print1();
    two();
    print2();
    three();
  }
}
