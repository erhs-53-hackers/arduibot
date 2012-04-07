#include "ParticleFilter.h"
/*
#include <stdlib.h>

__extension__ typedef int __guard __attribute__((mode (__DI__)));

int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);};
void __cxa_guard_release (__guard *g) {*(char *)g = 1;};
void __cxa_guard_abort (__guard *) {};



void * operator new[](size_t size);
void operator delete[](void * ptr);

void * operator new[](size_t size)
{
  return malloc(size);
}

void operator delete[](void * ptr)
{
  free(ptr);
}
*/

ParticleFilter::ParticleFilter(int num, int width, int height) {
  numOfParticles = num;  
  this->width = width;
  this->height = height;
  Serial.println("Starting");
  //particles = new Particle[num];
  //Serial.println("did new");
  
  for(int i=0;i<100;i++) {
    //particles[i] = Particle(width, height);
    //particles[i].randomize(width, height);
    Serial.println("Part");
    Serial.println(i);
   // Serial.println(particles[i].location.x);
  }
}
