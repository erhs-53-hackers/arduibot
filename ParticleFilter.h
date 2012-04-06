#include "Particle.h"

class ParticleFilter {
  public:
    int numOfParticles, width, height;
    double Fnoise, Tnosie, Snoise;
    Map map;
    Particle* particles;
    ParticleFilter(int num, Map map, int width, int height);
    void move(double turn, double forward);
    Point getLocation();
    void resample(double measurement);  
};
