#include "point.h"

void Point::output(std::ostream& os) const {
    os << "(" << x << ", " << y << ")";
}

void Point::input(std::istream& is) {
    while (true) {
        if (is >> x >> y) {
            break;
        }
        else {
            throw InputException("Coordinates must be two numbers separated by space");
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Point& a) {
    a.output(os);
    return os;
}

std::istream& operator>>(std::istream& is, Point& a) {
    a.input(is);
    return is;
}
