#include "rectangle.h"

double Rectangle::area() const {
    double a = abs(right.x - left.x);
    double b = abs(right.y - left.y);
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
