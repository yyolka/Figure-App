#include "point.h"

void Point::output(std::ostream& os) const {
    os << "(" << getX() << ", " << getY() << ")";
}

void Point::input(std::istream& is) {
    while (true) {
        double tmpX, tmpY;
        if (is >> tmpX >> tmpY) {
            setX(tmpX);
            setY(tmpY);
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

double Point::getX() const{
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double newX) {
    x = newX;
}

void Point::setY(double newY) {
    y = newY;
}
