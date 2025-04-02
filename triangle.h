#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
    std::string name;
    Point a, b, c;
public:
    Triangle() = default;
    Triangle(const std::string& name, Point a, Point b, Point c)
        : name(name), a(a), b(b), c(c) {
        double area = 0.5 * std::abs((c.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)));
        if (area == 0) {
            throw InvalidTriangleException("Triangle does not exist");
        }
    }
    double area() const override;
    void input(istream& is) override;
    void output(ostream& os) const override;
    std::string type() const override;
};

#endif // TRIANGLE_H
