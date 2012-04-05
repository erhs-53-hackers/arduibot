#include "Robot.h"

Robot::Robot() {  
  isRightInverted = false;
  isLeftInverted = false;
}

void Robot::move(double rotate, double move) {
  double L, R;
  if (move > 0.0) {
    if (rotate > 0.0) {
      L = move - rotate;
      R = max(move, rotate);
    } 
    else {
      L = max(move, -rotate);
      R = move + rotate;
    }
  } 
  else {
    if (rotate > 0.0) {
      L = -max(-move, rotate);
      R = move + rotate;
    } 
    else {
      L = move - rotate;
      R = -max(-move, -rotate);
    }
  }  

  if(isRightInverted) right.write(_map(R, -1.0, 1.0, 0, 84 * 2));
  else right.write(_map(R, -1.0, 1.0, 84 * 2, 0));

  if(isLeftInverted) left.write(_map(L, -1.0, 1.0, 0, 84 * 2));
  else left.write(_map(L, -1.0, 1.0, 84 * 2, 0));
}

void Robot::attach(int Lmotor, int Rmotor) {
  right.attach(Rmotor);
  left.attach(Lmotor); 
}

double Robot::_map(double x, double in_min, double in_max, double out_min, double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;  
}


