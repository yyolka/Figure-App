#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
    std::string name;
    Point left, right;
public:
    Rectangle() = default;
    Rectangle(const std::string& name, Point left, Point right)
        : name(name),  left(left), right(right){
        if (left.x >= right.x || left.x <= right.x) {
            throw InvalidRectangleException("Invalid rectangle coordinates.");
        }
    }
    double area() const override;
    void input(istream& is) override;
    void output(ostream& os) const override;
    std::string type() const override;
};

#endif // RECTANGLE_H
