#include "rectangle.h"

double Rectangle::area() const {
    double a = abs(right.getX() - left.getX());
    double b = abs(right.getY() - left.getY());
    return a * b;
}

void Rectangle::input(istream& is) {
    is >> name >> left >> right;
}

void Rectangle::output(ostream& os) const {
    os << "Rectangle: " << name << ", left point:" << left << ", right point: " << right << "\n";
}

std::string Rectangle::type() const {
    return "Rectangle";
}
