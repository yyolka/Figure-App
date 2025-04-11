#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

typedef enum {
    stopProgramChoice,
    addFigureChoice,
    printListParamsChoice,
    printListAreaChoice,
    printTotalSumChoice,
    sortByAreaChoice,
    removeShapeChoice,
    removeShapeByAreaChoice,
    addCircleChoice = 1,
    addTriangleChoice = 3,
    addRectangleChoice = 2
} ActionChoice;


class MenuManager {
private:
    vector<Shape *> shapes;
    unordered_map <int, void(MenuManager::*)()> mainFunctions;
    unordered_map <int, Shape*(MenuManager::*)()> addFigureFunctions;
    void runSubMenu();
    void printSubMenu();
    Shape* addCircle();
    Shape* addRectangle();
    Shape* addTriangle();
    void printListWithParams();
    void printListWithArea();
    void printTotalSum();
    void printMenu();
    double totalArea() const;
    static int compareByArea(Shape* a, Shape* b);
    void sortByArea();
    void removeShape();
    void removeShapesAboveArea();
    int choice;
    bool isRunning;
    void mainSetupCommands();
    void subSetupCommands();
    void mainRun();
    void subRun(int subChoice);
    int enterChoice();
public:
    MenuManager() : shapes(), choice(-1), isRunning() {
        mainSetupCommands();
        subSetupCommands();
    }
    void runMainProgramm();
    void exit();
};

#endif // MENU_H
