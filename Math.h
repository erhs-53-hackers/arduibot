#include <TrueRandom.h>
#include <arduino.h>
#define PI 3.14159265358979323846

double randn_notrig(double mu, double sigma);
double randn_trig(double mu, double sigma);
boolean lineSegmentIntersection(
double Ax, double Ay,
double Bx, double By,
double Cx, double Cy,
double Dx, double Dy,
double *X, double *Y);

double nextDouble();



