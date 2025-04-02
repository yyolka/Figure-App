#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
    std::string name;
    Point center;
    double radius;
public:
    Circle() = default;
    Circle(const std::string& name, Point center, double radius)
        : name(name), center(center), radius(radius) {
    }
    double area() const override;
    void input(istream& is) override;
    void output(ostream& os) const override;
    std::string type() const override;
};


#endif // CIRCLE_H
