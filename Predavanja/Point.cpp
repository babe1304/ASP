#include <iostream>
#include <math.h>
#include "Point.h"

Point::Point(double x, double y) : x(x), y(x) {};
void Point::mirrorX(double xValue) { x = xValue - (x - xValue); }
void Point::mirrorY(double yValue) { y = yValue - (y - yValue); }

double Point::distance(Point other) {
    return sqrt((x - other.x) * (x - other.x) +
                    (y - other.y) * (y - other.y));
    }
Point Point::swapXY() { return { y, x}; }
