#include "triangle.h"

double Triangle::area() const {
    return 0.5 * std::abs((c.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)));
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
