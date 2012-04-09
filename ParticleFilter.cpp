
#include "ParticleFilter.h"



ParticleFilter::ParticleFilter(int width, int height, double Fnoise, double Tnoise, double Snoise) {
  this->width = width;
  this->height = height;
  this->Fnoise = Fnoise;
  this->Tnoise = Tnoise;
  this->Snoise = Snoise;

  for(int i=0; i<PART_COUNT; i++) {
    particles[i].x = nextDouble() * width;
    particles[i].y = nextDouble() * height;
    particles[i].theta = nextDouble() * 2.0 * PI;
  }
}

void ParticleFilter::move(double turn, double forward) {
  for(int i=0; i<PART_COUNT; i++) {
    Serial.println(particles[i].theta);
    particles[i].theta += turn + randn_notrig(0, Tnoise);    
    particles[i].theta = circle(particles[i].theta, 2.0 * PI);
    Serial.println(particles[i].theta);
    double dist = forward + randn_notrig(0, Fnoise);

    particles[i].x += cos(particles[i].theta) * dist;
    particles[i].y += sin(particles[i].theta) * dist;
  }

}

Particle ParticleFilter::getLocation() {
  Particle part;
  part.x = 0;
  part.y = 0;
  part.theta = 0;
  for(int i=0; i<PART_COUNT; i++) {
    part.x += particles[i].x;
    part.y += particles[i].y;
    part.theta += circle(particles[i].theta - particles[0].theta + PI,
    2.0 * PI)
      + particles[0].theta - PI;
  }
  part.x /= PART_COUNT;
  part.y /= PART_COUNT;
  part.theta /= PART_COUNT;

  return part;
}

void ParticleFilter::measureProbability(double* probs, double measurement) {
  double len = width * height;
  double dists[PART_COUNT];
  
  for(int i = 0; i<PART_COUNT; i++) {
    Point p;
    
    p.x = particles[i].x + cos(particles[i].theta) * len;
    p.y = particles[i].y + sin(particles[i].theta) * len;
    
    Serial.println(p.x);
    Serial.println(p.y);
    Point intersect;
    double best = len + 1;

    for(int a=0; a<BAR_COUNT; a++) {
      double x, y;
      bool hit = MAP.barriers[a]->collides(particles[i].x, particles[i].y,
      p.x, p.y,
      &x, &y);

      if(hit) {
        Serial.println("HIT!!!");
        double dist = distance(particles[i].x, particles[i].y, x, y);
        Serial.println(a);
        Serial.println(x);
        Serial.println(y);
        if(dist < best) {
          dists[i] = dist;
          intersect.x = x;
          intersect.y = y;
          best = dist;
        }
      }
    }
    probs[i] = Gaussian(best, Snoise, measurement);
  }
  
  for(int i=0; i<PART_COUNT; i++) {
    //cout<<i<<"|"<<probs[i]<<endl;
    Serial.print(i);
    Serial.print("|");
    Serial.print(probs[i], DEC);
    Serial.print(", Dist:");
    Serial.println(dists[i]);
  }  
}


void ParticleFilter::resample(double measurement) {

  double probs[PART_COUNT];
  
  measureProbability(probs, measurement);  
 
  int best = 0;
  for(int i=0; i<PART_COUNT; i++) {
    if(probs[i] > probs[best]) {
      best = i;
    }
  }


  //cout << "Best:" << best<<endl;
  //Serial.print("Best:");
  //Serial.println

  double B = 0.0;
  int index = (int) nextDouble() * PART_COUNT;
  Particle new_parts[PART_COUNT];

  for(int i=0; i<PART_COUNT; i++) {
    B += nextDouble() * 2.0 * probs[best];
    while(B > probs[index]) {
      B -= probs[index];
      index = circle(index+1, PART_COUNT);
    }
    new_parts[i].x = particles[index].x;
    new_parts[i].y = particles[index].y;
    new_parts[i].theta = particles[index].theta;
  }



  for(int i=0; i<PART_COUNT; i++) {
    particles[i].x = new_parts[i].x;
    particles[i].y = new_parts[i].y;
    particles[i].theta = new_parts[i].theta;
  }  
}

void ParticleFilter::print() {
  //cout << "Particles("<<PART_COUNT<<"):"<<endl;
  Serial.print("Particles(");
  Serial.print(PART_COUNT);
  Serial.println("):");
  for(int i=0; i<PART_COUNT; i++) {
    //cout << i << "|";
    Serial.print(i);
    Serial.print("|");
    //cout << "X:" << particles[i].x << ", Y:" << particles[i].y;
    Serial.print("X:");
    Serial.print(particles[i].x);
    Serial.print(", Y:");
    Serial.print(particles[i].y);
    //cout << ", Theta:" << particles[i].theta * 180 / PI<<endl;
    Serial.print(", Theta:");
    Serial.println(particles[i].theta * 180 / PI);
  }

}

