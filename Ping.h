#include <Arduino.h>
#define INCHES 0
#define CENTIMETERS 1
class Ping {
  public:
    Ping(int digitalPort);
    long getDistance();    
    int units;
  private:
    int pin;  
    long microsecondsToInches(long microseconds);
    long microsecondsToCentimeters(long microseconds);
    long getDuration();
    
};
