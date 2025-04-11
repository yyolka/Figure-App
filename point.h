#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <limits>
#include "error.h"

typedef class Point {
private:
    double x, y;
    friend std::ostream& operator<<(std::ostream& os, const Point& a);
    void input(std::istream& is);
    void output(std::ostream& os) const;
    friend std::istream& operator>>(std::istream& is, Point& a);
public:
    double getX() const;
    double getY()const;
    void setX(double newX);
    void setY(double newY);
} Point;

#endif // POINT_H
