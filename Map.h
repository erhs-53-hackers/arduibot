#include "Math.h"
#define BAR_COUNT 8
struct Point {
    Point();
    Point(double, double);
    double x, y;
};
/*
struct Barrier {
    virtual bool collides(double, double, double, double, double*, double*) = 0;
};
*/
struct Line/* : public Barrier*/ {
    Point p1, p2;
    Line(Point, Point);
    Line();
    /*virtual*/ bool collides(double, double, double, double, double*, double*);
};

struct Map {
    //Line* barriers[BAR_COUNT];
    Line barriers[BAR_COUNT];
    /*
    Line line1;
    Line line2;
    Line line3;
    Line line4;
    Line line5;
    Line line6;
    Line line7;
    Line line8;
    */
    Map();

};









