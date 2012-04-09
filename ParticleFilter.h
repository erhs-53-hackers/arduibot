#include "Particle.h"
#include "Map.h"
#define PART_COUNT 20

using namespace std;

class ParticleFilter {
  public:
    int numOfParticles, width, height;
    double Fnoise, Tnoise, Snoise;
    Particle particles[PART_COUNT];
    Map MAP;
    ParticleFilter(int width, int height, double Fnoise, double Tnoise, double Snoise);
    void move(double turn, double forward);
    Particle getLocation();
    void measureProbability(double* probs, double measurement);
    void resample(double measurement);
    void print();

};
