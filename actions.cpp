#include "actions.h"


Shape* CollectionActions::addCircle() {
    cout << "Input name, center and radius:\n";
    Shape* shape = new Circle();
    cin >> *shape;
    shapes.push_back(shape);
    cout << "Circle added\n";
    return shape;
}

Shape* CollectionActions::addRectangle() {
    cout << "Input name, left and right points:\n";
    Shape* shape = new Rectangle();
    cin >> *shape;
    shapes.push_back(shape);
    cout << "Rectangle added\n";
    return shape;
}

Shape* CollectionActions::addTriangle() {
    cout << "Input name and three points:\n";
    Shape* shape = new Triangle();
    cin >> *shape;
    shapes.push_back(shape);
    cout << "Triangle added\n";
    return shape;
}


double CollectionActions::totalArea() const {
    double total = 0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

int compareByArea(Shape* a, Shape* b) {
    return a->area() < b->area();
}

int compareArea(Shape* a, double area) {
    return a->area() < area;
}

void CollectionActions::sortByArea() {
    std::sort(shapes.begin(), shapes.end(), compareByArea);
    std::cout << "Shapes sorted by area.\n";
}

void CollectionActions::removeShapesAboveArea(double area) {
    shapes.erase(
        std::remove_if(shapes.begin(), shapes.end(),
                       [area](Shape* a) { return a->area() > area; }
                       ),
        shapes.end()
        );
}

void CollectionActions::removeShape(size_t index) {
    if (index - 1 >= shapes.size()) {
        throw std::out_of_range("Index out of range");
    }
    delete shapes[index - 1];
    shapes.erase(shapes.begin() + index - 1);
    cout << "Shape has been deleted\n";
}


