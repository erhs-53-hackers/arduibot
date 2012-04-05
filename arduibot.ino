#include "Gyro.h"
#include "PIDController.h"
#include "Ping.h"
#include "Robot.h"
#include <Wire.h>
#include <Servo.h>
#define SPEED 200


Gyro gyro;
Ping ultra(7);
Robot robot;
PIDController PID(0.05, 0.00000, 0.1, -1, 1);//21.1967086791, 0.001, 29.1900043487
PIDController temp(0.1, 0.00000, 0.4, -1, 1);

Servo left, right;
boolean transmitting = false;
String message = "";



double modAngle(double angle) {
  while(angle > 360) { 
    angle -= 360;    
  }
  while(angle < -360) {
    angle += 360;    
  }
  return angle;
}

void recieveMessage() {
  if (Serial.available() > 0) {
    if(!transmitting) {
      message = "";
      transmitting = true;      
    }    
    char inByte = (char)Serial.read();
    message += inByte;

  } 
  else {
    transmitting = false;
    if(message != "") {
      if(message == "reset") {
        gyro.reset();
        PID.setpoint = gyro.getZ();
      } 
      else {
        char s[message.length() + 1];
        message.toCharArray(s, message.length() + 1);
        PID.setpoint = atoi(s);
      }
    }
  }
  
  
}
void followAngle(double val) {
  robot.move(-val, 0.5); //temp.doPID(ultra.getDistance())
  
}

 
double _map(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;  
}
void t(double val) {
  
  robot.move(-PID.doPID(gyro.getZ()), -val);
  
}
void setup(){  
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Loading...");

  
  gyro.configure(); 
  PID.setpoint = gyro.getZ();
  PID.action = &followAngle; 
 
  temp.setpoint = 2; 
  temp.action = &t;

  robot.attach(9, 10);
  robot.isRightInverted = true;
  


  Serial.println("Loaded");
  

  //robot.move(0.6, 1);
  
  
  
  
 
 
}



void loop(){ 
  //84
  
  PID.doPID(gyro.getZ());
 
 

  
 // temp.doPID(ultra.getDistance());
  //Serial.println(ultra.getDistance());
  
  
  //Serial.print(inches);
  //Serial.print("in, ");
  //Serial.print(cm);
  //Serial.print("cm");
  //Serial.println();
  
  
  
  
  
  //recieveMessage();

 
  //int leftS = analogRead(A1);
  //int rightS = analogRead(A0);
  
  
  //delay(200);

}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}












