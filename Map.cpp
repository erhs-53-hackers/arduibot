#include "Map.h"

Line::Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}

Line::Line() {

}

bool Line::collides(double Cx, double Cy,
                    double Dx, double Dy,
                    double *X, double *Y) {
    return lineSegmentIntersection(p1.x, p1.y, p2.x, p2.y, Cx, Cy, Dx, Dy, X, Y);
}

Point::Point() {

}
Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Map::Map() {
/*
    line1 = Line(Point(0, 0), Point(5, 0));
    line2 = Line(Point(5, 0), Point(5, 5));
    line3 = Line(Point(5, 5), Point(3, 5));
    line4 = Line(Point(3, 5), Point(3, 4));
    line5 = Line(Point(3, 4), Point(2, 4));
    line6 = Line(Point(2, 4), Point(2, 5));
    line7 = Line(Point(2, 5), Point(0, 5));
    line8 = Line(Point(0, 5), Point(0, 0));
    */
    
    barriers[0] = Line(Point(0, 0), Point(5, 0));//&line1;
    barriers[1] = Line(Point(5, 0), Point(5, 5));//&line2;
    barriers[2] = Line(Point(5, 5), Point(3, 5));//&line3;
    barriers[3] = Line(Point(3, 5), Point(3, 4));//&line4;
    barriers[4] = Line(Point(3, 4), Point(2, 4));//&line5;
    barriers[5] = Line(Point(2, 4), Point(2, 5));//&line6;
    barriers[6] = Line(Point(2, 5), Point(0, 5));//&line7;
    barriers[7] = Line(Point(0, 5), Point(0, 0));//&line8;

}

