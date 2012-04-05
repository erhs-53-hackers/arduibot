

class PIDController {
  public:
    PIDController(double kp, double ki, double kd, double min=-1000, double max=1000);    
    double doPID(double input);
    double setpoint, error;
    void (*action)(double value);
    
    
  private:
    double kp, ki, kd, P, I, D, max, min;
    
  
};
