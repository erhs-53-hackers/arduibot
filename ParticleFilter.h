#include "Particle.h"
#include <arduino.h>
class ParticleFilter {
  public:
    int numOfParticles, width, height;
    double Fnoise, Tnosie, Snoise;
    Map map;
    Particle particles[490];
    ParticleFilter(int num, int width, int height);
    void move(double turn, double forward);
    Point getLocation();
    void resample(double measurement);  
};
