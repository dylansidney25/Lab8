//this code uses the arduino mega board
//by performing a voltage devider a percentage of 180 is found for the entry of angle for each servo motor
//100% of servo rotation (equal to 180 degrees) is achived at 5 volts
//the circuit build uses a 1k potentiometer for each servo.
//starting at 0, the pot will have 0 volts across it, and as you increas the value of Rpot you will increase the voltage across it. the max voltage being 5
//the input voltage will be devided by 1023 to find the percentage of max
//that percentage will then be multiplied by 180 to find said percentage of 180 and be set to the servo angle.

#include <Servo.h>

int ServoRead1 = A0;
int ServoRead2 = A1;
int ServoValue1;
int ServoValue2;
float ServoPercent1;
float ServoPercent2;
float ServoAngle1;
float ServoAngle2;
int ServoPin1 = 2;
int ServoPin2 = 3;

Servo Servo1;
Servo Servo2;

void setup() {
  Serial.begin(9600);
  pinMode(ServoRead1, INPUT);   //Servo Read pin
  pinMode(ServoRead2, INPUT);   //servo Read pin

  Servo1.attach(ServoPin1);     //Servo Signal Output
  Servo2.attach(ServoPin2);     //servo signal oputput
  
  Servo1.write(0);              //starts servo at 0
  Servo2.write(0);              //starts servo at 0

}

void loop() {  
  ServoValue1 = analogRead(ServoRead1);
  ServoValue2 = analogRead(ServoRead2);
  
  ServoPercent1 = ServoValue1 / 1023.0;
  ServoPercent2 = ServoValue2 / 1023.0;
  
  Serial.println(ServoPercent1);
  Serial.println(ServoPercent2);
  Serial.println(" ");
  
  ServoAngle1 = ServoPercent1 * 180;
  ServoAngle2 = ServoPercent2 * 180; 
  
  Servo1.write(ServoAngle1);
  Servo2.write(ServoAngle2);

}
