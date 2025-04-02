#ifndef ACTIONS_H
#define ACTIONS_H

#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

typedef enum {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE
} ActionChoice;


class CollectionActions {
public:
    std::vector<Shape *> shapes;
    Shape* addCircle();
    Shape* addRectangle();
    Shape* addTriangle();
    double totalArea() const;
    void sortByArea();
    void removeShape(size_t index);
    void removeShapesAboveArea(double area);
    friend class Output;
};



#endif // ACTIONS_H
