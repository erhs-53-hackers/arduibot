#include "PIDController.h"

PIDController::PIDController(double kp, double ki, double kd, double min, double max) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;  
  this->max = max;
  this->min = min;
}

double PIDController::doPID(double input) {
  
  error = input - setpoint;
  D = error - P;
  P = error;
  double _I = (I + error) * ki;
  if(_I < max && _I > min) I += error;
  
  double output = -kp * P - ki * I - kd * D;
  
  
  if(output > max) output = max;
  if(output < min) output = min;
  
  action(output);
  
  return output;  
}
