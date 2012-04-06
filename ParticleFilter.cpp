#include "ParticleFilter.h"

ParticleFilter::ParticleFilter(int num, Map map, int width, int height) {
  numOfParticles = num;
  this->map = map;
  this->width = width;
  this->height = height;
 // particles = new Particle[num];
}
