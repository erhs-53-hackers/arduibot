#include "Ping.h"

Ping::Ping(int digitalPort) {
  pin = digitalPort;
  units = INCHES;
}

long Ping::getDistance() {//inches
  long time = getDuration();
  
  if(units == INCHES) {
    time = microsecondsToInches(time);        
  } else {
    time = microsecondsToCentimeters(time);
  }
  
  return time;
  
}

long Ping::getDuration() {  
  pinMode(pin, OUTPUT);
  
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin, LOW);
  
  pinMode(pin, INPUT);  
  
 
  return pulseIn(pin, HIGH);
}

long Ping::microsecondsToInches(long microseconds) {  
  return microseconds / 74 / 2;
}

long Ping::microsecondsToCentimeters(long microseconds) { 
  return microseconds / 29 / 2;
}
