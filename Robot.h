#include <Servo.h>
#include <arduino.h>


class Robot {
  public:
    Robot();
    void attach(int Lmotor, int Rmotor);
    void move(double rotate, double move);
    boolean isRightInverted, isLeftInverted;
    
  private:
    Servo right, left;
    double _map(double x, double in_min, double in_max, double out_min, double out_max);  
  
};
