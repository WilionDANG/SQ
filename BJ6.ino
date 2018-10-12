/*
   Sketch1.ino

   Created: 10/13/2018 12:47:24 AM
   Author: D1470
*/
#include<Wire.h>
#include<string.h>
#include<math.h>
#include<Servo.h>
#include<path.h>
Servo myservo;
Servo servol1;
int Q = 1570; //N20转动间隔时间
int W = 4; //从机地址
int di = 1130; //地面射球
int sky = 1410; //空中射球
int E = 2; //射球次数
int A = 0; //人物列表
double X = 0;
double Y = 0;
double P = 0;
float step_count = 0;
float val = 0, val2 = 0;

void plectrum() { //N20转动0
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(Q);
  digitalWrite(2, LOW);
}

void receiveEvent(int howMany) {
  while (0 < Wire.available()) { // loop through all but the last
    A = Wire.read(); // receive byte as a character
    Serial.print(A);         // print the character
  }
}
void SHOTDI() {
  Serial.println(1000);
  servol1.writeMicroseconds(di);
  myservo.writeMicroseconds(di);
  for (int t = 0; t < E; t++)
  {
    plectrum();
  }
}

void SHOTSKY() {
  for (int t = 0; t < E; t++)
  {
    // turnport();
    servol1.writeMicroseconds(sky);
    myservo.writeMicroseconds(sky);
    plectrum();
  }
}
void setup()
{
  Wire.begin(4);
  Serial.begin(9600);
  myservo.attach(10);
  servol1.attach(9);
  myservo.writeMicroseconds(2000);
  servol1.writeMicroseconds(2000);

  //delay(3500);
  myservo.writeMicroseconds(1000);
  servol1.writeMicroseconds(1000);
  //delay(2000);
  myservo.writeMicroseconds(1000);
  servol1.writeMicroseconds(1000);
  pinMode(2, OUTPUT);
  /* add setup code here, setup code runs once when the processor starts */
  Wire.onReceive(receiveEvent);
}

void loop()
{
  if (A == 1)
  {
    SHOTDI();
    Serial.println(A);
  }
  else if (A == 3)
  {
    SHOTSKY();
  }  /* add main program code here, this code starts again each time it ends */
  else
  {
    delay(100);
  }
}
