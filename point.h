#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <limits>
#include "error.h"

typedef struct Point {
    double x, y;
    friend std::ostream& operator<<(std::ostream& os, const Point& a);
    void input(std::istream& is);
    void output(std::ostream& os) const;
    friend std::istream& operator>>(std::istream& is, Point& a);
} Point;

#endif // POINT_H
