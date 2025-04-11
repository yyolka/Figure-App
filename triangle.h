#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
    Point a, b, c;
public:
    Triangle() = default;
    Triangle(const string& name, Point a, Point b, Point c)
        : Shape{name}, a(a), b(b), c(c) {
        double area = 0.5 * abs((c.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())));
        if (area == 0) {
            throw InvalidTriangleException("Triangle does not exist");
        }
    }
    double area() const override;
    void input(istream& is) override;
    void output(ostream& os) const override;
    string type() const override;
};

#endif // TRIANGLE_H
