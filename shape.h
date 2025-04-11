#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <memory>
#include "point.h"
#include "error.h"

using namespace std;

class Shape {
protected:
    string name;
public:
    virtual ~Shape() = default;
    Shape() = default;
    explicit Shape(const string& name) : name(name) {}
    virtual double area() const = 0;
    virtual void input(istream& is) = 0;
    virtual void output(ostream& os) const = 0;
    virtual string type() const = 0;
    friend istream& operator>>(istream& is, Shape& a) {
        a.input(is);
        return is;
    }
    friend ostream& operator<<(ostream& os, Shape& a) {
        a.output(os);
        return os;
    }
};

#endif // SHAPE_H
