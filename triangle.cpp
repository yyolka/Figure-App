#include "triangle.h"

double Triangle::area() const {
    return 0.5 * std::abs((c.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())));
};

void Triangle::input(istream& is) {
    is >> name >> a >> b >> c;
}

void Triangle::output(ostream& os) const {
    os << "Triangle: " << name << " Points: " << a << ", " << b << ", " << c << "\n";
}

std::string Triangle::type() const {
    return "Triangle";
}
