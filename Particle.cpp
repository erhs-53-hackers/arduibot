#include "Particle.h"

Particle::Particle(int width, int height) {
  location.x = nextDouble() * width;
  location.y = nextDouble() * height;
  orientation = nextDouble() * 2.0 * PI;  
}

void Particle::move(double turn, double forward, double Fnoise, double Tnoise) {
  orientation = orientation + turn + randn_notrig(0, Tnoise);
  double dist = forward + randn_notrig(0, Fnoise);

  location.x += cos(orientation) * dist;
  location.y += sin(orientation) * dist;
}

double Particle::Gaussian(double mu, double sigma, double x) {
  return exp(-pow(mu - x, 2) / pow(sigma, 2) / 2.0 ) / sqrt(2.0 * PI * pow(sigma, 2));
}

double Particle::distance(Point p1, Point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void Particle::measureProb(double measurement, Line map[], double Snoise, int len) {
  probability =  1.0;
  Point p = location;
  p.x += cos(orientation) * len;
  p.y += sin(orientation) * len;

  Point intersect;
  double best = len + 1;
  Serial.print("Size:");
  Serial.println(sizeof(map)/sizeof(Line));
  
  
  

  for(int i=0;i<4;i++) {
    double x, y;
    boolean hit = lineSegmentIntersection(location.x, location.y,
    p.x, p.y,
    map[i].p1.x, map[i].p1.y,
    map[i].p2.x, map[i].p2.y,
    &x, &y);
    if(hit) {
      Serial.println("HIT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      Point foo;
      foo.x = x;
      foo.y = y;
      double dist = distance(location, foo);
      if(dist < best) {        
        intersect = foo;
        best = dist;      
      }
    }
  }
  
  Serial.print("Intersect: X:");
  Serial.print(intersect.x);
  Serial.print(", Y:");
  Serial.println(intersect.y);
  
  probability = Gaussian(best, Snoise, measurement);


}




