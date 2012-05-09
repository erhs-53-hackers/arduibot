#include <TrueRandom.h>
#include "Gyro.h"
#include "PIDController.h"
#include "Ping.h"
#include "Robot.h"
#include "ParticleFilter.h"
#include <Wire.h>
#include <Servo.h>
#include "Math.h"








void setup(){
  randomSeed(analogRead(0));  
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Loading...");
  
  Serial.println("Loaded");
  /*
  filter.particles[0].x = 2;
  filter.particles[0].y = 3;
  filter.particles[0].theta = 3 * PI / 2;
  filter.print();  
  filter.resample(3);
  filter.print();
  */
  ParticleFilter filter(5, 5, 0.05, 0.05, 0.5);
  
  
  filter.print();
  filter.resample(3);
  filter.move(PI, 1);
  filter.resample(1);
  filter.print();
  
  
  
  
  
  
  Particle part = filter.getLocation();
  Serial.print("X:");
  Serial.print(part.x);
  Serial.print(", Y:");
  Serial.print(part.y);
  Serial.print(", Theta:");
  Serial.println(part.theta * 180 / PI);
  
  
  
  
}

void loop(){ 
  Serial.println("LOOPING");
  
 
 

  
 
}











