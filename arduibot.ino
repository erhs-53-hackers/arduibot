#include <TrueRandom.h>
#include "Gyro.h"
#include "PIDController.h"
#include "Ping.h"
#include "Robot.h"
#include "Particle.h"
#include <Wire.h>
#include <Servo.h>
#include "Math.h"
#define SPEED 200


Gyro gyro;
Ping ultra(7);
Robot robot;
PIDController PID(0.05, 0.00000, 0.1, -1, 1);//21.1967086791, 0.001, 29.1900043487
PIDController temp(0.1, 0.00000, 0.4, -1, 1);
Particle part(100, 100);
Line _map[4];

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
  robot.move(-val, 0); //temp.doPID(ultra.getDistance())
  
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
  Point p1, p2;
  
  Line line1, line2, line3, line4;
  p1.x = 0;
  p1.y = 0;
  p2.x = 100;
  p2.y = 0;
  line1.p1 = p1;
  line1.p2 = p2;
  
  p1.x = 100;
  p1.y = 0;
  p2.x = 100;
  p2.y = 100;
  line2.p1 = p1;
  line2.p2 = p2;
  
  p1.x = 100;
  p1.y = 100;
  p2.x = 0;
  p2.y = 100;
  line3.p1 = p1;
  line3.p2 = p2;
  
  p1.x = 0;
  p1.y = 100;
  p2.x = 0;
  p2.y = 0;
  line4.p1 = p1;
  line4.p2 = p2;
  
  _map[0] = line1;
  _map[1] = line2;
  _map[2] = line3;
  _map[3] = line4;
  Serial.println(line2.p1.x);
  
  part.location.x = 5;
  part.location.y = 5;
  part.orientation = 3*PI/2;
  part.measureProb(5, _map, 0.1, 10000);
  /*
  double x, y;
  lineSegmentIntersection(5, 5, -4, -10, 0, 0, 100,0, &x, &y);

  Serial.println("Loaded");
  Serial.println(x, DEC);
  Serial.println(y, DEC);
  */
  

  //robot.move(0.6, 1);
  
  
  
  
  
 
 
}

void loop(){ 
  //84
 //Serial.println("yo");
  PID.doPID(gyro.getZ());
  //Serial.println(rand() / (32767.0 + 1.0), DEC);
  Serial.print("X:");
  Serial.print(part.location.x);
  Serial.print(", Y:");
  Serial.print(part.location.y);
  Serial.print(", Theta:");
  Serial.print(part.orientation);
  Serial.print(", Prob:");
  Serial.println(part.probability, DEC);
 
 

  
 
}











