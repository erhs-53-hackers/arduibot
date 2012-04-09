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

    line1 = Line(Point(0, 0), Point(5, 0));
    line2 = Line(Point(5, 0), Point(5, 5));
    line3 = Line(Point(5, 5), Point(0, 5));
    line4 = Line(Point(0, 5), Point(0, 0));

    barriers[0] = &line1;
    barriers[1] = &line2;
    barriers[2] = &line3;
    barriers[3] = &line4;

}

