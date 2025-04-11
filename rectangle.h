#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
    Point left, right;
public:
    Rectangle() = default;
    Rectangle(const string& name, Point left, Point right)
        : Shape{name},  left(left), right(right){
        if (left.getX() >= right.getX() || left.getY() <= right.getY()) {
            throw InvalidRectangleException("Invalid rectangle coordinates.");
        }
    }
    double area() const override;
    void input(istream& is) override;
    void output(ostream& os) const override;
    string type() const override;
};

#endif // RECTANGLE_H
