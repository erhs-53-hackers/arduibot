#include <arduino.h>
#include "Math.h"
#include "Map.h"


//struct Particle;
struct Particle {
  double orientation, probability, x, y;  
};

/*
class Particle {
  public:
    double orientation, probability;    
    Point location;    
    Particle(int width, int height);
    Particle();
    void move(double turn, double forward, double Fnoise, double Tnoise);
    void measureProb(double measurement, Line map[], double Snoise, int len);
    void randomize(int width, int height);
    
  private:    
    double Gaussian(double mu, double sigma, double x);
    double distance(Point p1, Point p2); 
  
};
*/
