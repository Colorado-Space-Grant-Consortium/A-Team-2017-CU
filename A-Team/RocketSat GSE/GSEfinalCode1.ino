/*
 * The following code is for the RockSat X GSE dummy payload. 
 * This code is written for an Arduino Due, though it may addapted for use on an Arduino Mega.
 * 
 * Pin assignments:
 * Pins (4-13) = analog output to pins (1-10) on the 37 pin conector
 * Pins (22-39) = parallel output to pins (11-16, 20-29) on the 36 pin connector
 * Pins (18tx, 19rx) = RS232 outputs to RS232 connector
 * 
 * Date: 5/8/2018
 * Mikaela Dobbin, Cameron Humphreys, Hanna Galimanis
*/

void setup() {
  //Set data rate and send serial communication through arduino tx and rx pins
  Serial1.begin(9600);
  //analog pins
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT); 
  //parallel pines
  pinMode (22,OUTPUT);
  pinMode (23,OUTPUT);
  pinMode (24,OUTPUT);
  pinMode (25,OUTPUT);
  pinMode (26,OUTPUT);
  pinMode (27,OUTPUT);
  pinMode (28,OUTPUT);
  pinMode (29,OUTPUT);
  pinMode (30,OUTPUT);
  pinMode (31,OUTPUT);
  pinMode (32,OUTPUT);
  pinMode (33,OUTPUT);
  pinMode (34,OUTPUT);
  pinMode (35,OUTPUT);
  pinMode (36,OUTPUT);
  pinMode (37,OUTPUT);
  pinMode (38,OUTPUT);
  pinMode (39,OUTPUT);
}

void squareWaves(){
  //SQUARE WAVES
  digitalWrite(13, HIGH);
  delayMicroseconds(100); 
  digitalWrite(13, LOW);
  delayMicroseconds(1000 - 100);

  digitalWrite(12, HIGH);
  delayMicroseconds(200); 
  digitalWrite(12, LOW);
  delayMicroseconds(1000 - 200);

  digitalWrite(11, HIGH);
  delayMicroseconds(300); 
  digitalWrite(11, LOW);
  delayMicroseconds(1000 - 300);

  digitalWrite(10, HIGH);
  delayMicroseconds(400); 
  digitalWrite(10, LOW);
  delayMicroseconds(1000 - 400);

  digitalWrite(9, HIGH);
  delayMicroseconds(500); 
  digitalWrite(9, LOW);
  delayMicroseconds(1000 - 500);

  digitalWrite(8, HIGH);
  delayMicroseconds(600); 
  digitalWrite(8, LOW);
  delayMicroseconds(1000 - 600);

  digitalWrite(7, HIGH);
  delayMicroseconds(700); 
  digitalWrite(7, LOW);
  delayMicroseconds(1000 - 700);

  digitalWrite(6, HIGH);
  delayMicroseconds(800); 
  digitalWrite(6, LOW);
  delayMicroseconds(1000 - 800);

  digitalWrite(5, HIGH);
  delayMicroseconds(900); 
  digitalWrite(5, LOW);
  delayMicroseconds(1000 - 900);

  digitalWrite(4, HIGH);
  delayMicroseconds(1000); 
  digitalWrite(4, LOW);
  delayMicroseconds(1000 - 1000);
}

void loop() {
  //RS-232 communication
  Serial1.print(" Space, the final frontier.\n ...These are the voyages of the Starship Enterprise.\n Its continuing mission to explore strange new worlds,\n to seek out new life and new civilization,\n to boldly go where no one has gone before…\n\n");

  //squareWaves for continuous output through each loop
  squareWaves();

  //PARALLEL on sequence
  int i = 22;
  while(i!=40){
    digitalWrite(i, HIGH);
    delay(1000);
    i++;
    squareWaves();
  }
  delay(1000);
  //off sequence
  i = 39;
  while(i!=21){
    digitalWrite(i, LOW);
    delay(1000);
    i--;
    squareWaves();
  }
}
