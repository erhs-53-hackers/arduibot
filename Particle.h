#include <arduino.h>
#include "Math.h"
struct Point {
  double x, y;  
};
struct Line {
  Point p1, p2;  
};

typedef Line* Map;

class Particle {
  public:
    double orientation, probability;    
    Point location;    
    Particle(int width, int height);
    double sense(Point landmarks[]);
    void move(double turn, double forward, double Fnoise, double Tnoise);
    void measureProb(double measurement, Line map[], double Snoise, int len);
    
  private:
    double Gaussian(double mu, double sigma, double x);
    double distance(Point p1, Point p2); 
  
};
