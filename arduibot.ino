#include <TrueRandom.h>
#include "Gyro.h"
#include "PIDController.h"
#include "Ping.h"
#include "Robot.h"

#include "ParticleFilter.h"
#include <Wire.h>
#include <Servo.h>
#include "Math.h"






/*
Particle part1(100, 100);
Particle part2(100, 100);
Particle part3(100, 100);
Particle part4(100, 100);
Particle part5(100, 100);
Particle part6(100, 100);
Particle part7(100, 100);
Particle part8(100, 100);
Particle part9(100, 100);
Particle part10(100, 100);
*/
//Line _map[4];






double modAngle(double angle) {
  while(angle > 360) { 
    angle -= 360;    
  }
  while(angle < -360) {
    angle += 360;    
  }
  return angle;
}
/*
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
*/
Particle particles[1000];
void setup(){  
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Loading...");
  //ParticleFilter filter(100, 100, 100);  
  
  

  //robot.attach(9, 10);
  //robot.isRightInverted = true;
  /*
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
  */
  
  //filter.map = _map;
  Serial.println("Loaded");
  
 
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
  Serial.println("LOOPING!!!!!!!!!!!!!!!!!!!");
  
 
 

  
 
}











