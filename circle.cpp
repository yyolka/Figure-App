#include "circle.h"

double Circle::area() const{
    return M_PI * radius * radius;
}

void Circle::input(istream& is) {
    is >> name >> center;
    if (!(std::cin >> radius)) {
        throw InvalidCircleException("Radius must be number.");
    }
    std::cin.ignore();
    if (radius <= 0) {
        throw InvalidCircleException("Radius must be positive.");
    }
}

void Circle::output(ostream& os) const {
    os << "Circle: " << name << ", radius: " << radius << ", center: " << center << "\n";
}

std::string Circle::type() const {
    return "Circle";
}
