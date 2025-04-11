#include "menu.h"

void MenuManager::runMainProgramm() {
    isRunning = true;
    do {
        printMenu();
        choice = enterChoice();
        try {
            mainRun();
        } catch (const exception& e) {
            cerr<< e.what() << endl;
        } catch (...) {
            cerr << "Unknown error occurred.\n";
        }
    } while (isRunning);
}

void MenuManager::runSubMenu() {
    int subChoice;
    printSubMenu();
    subChoice = enterChoice();
    if (subChoice < 1 | subChoice > 3)
        throw InputException("Number should be betwwe 1 and 3");
    subRun(subChoice);
}

void MenuManager::mainRun() {
    auto it = mainFunctions.find(choice);
    (this->*(it->second))();
}

void MenuManager::subRun(int subChoice) {
    auto it = addFigureFunctions.find(subChoice);
    Shape* newShape = (this->*(it->second))();
    shapes.push_back(newShape);
}

int MenuManager::enterChoice() {
    cout << "Enter your choice: ";
    while (!(cin >> choice) || (choice < 0 || choice > 9)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    return choice;
}

void MenuManager::exit() {
    cout << "Exiting..." << endl;
    isRunning = false;
}

void MenuManager::mainSetupCommands() {
    mainFunctions[addFigureChoice] = &MenuManager::runSubMenu;
    mainFunctions[printListParamsChoice] = &MenuManager::printListWithParams;
    mainFunctions[printListAreaChoice] = &MenuManager::printListWithArea;
    mainFunctions[printTotalSumChoice] = &MenuManager::printTotalSum;
    mainFunctions[sortByAreaChoice] = &MenuManager::sortByArea;
    mainFunctions[removeShapeChoice] = &MenuManager::removeShape;
    mainFunctions[removeShapeByAreaChoice] = &MenuManager::removeShapesAboveArea;
    mainFunctions[stopProgramChoice] = &MenuManager::exit;
}

void MenuManager::subSetupCommands() {
    addFigureFunctions[addCircleChoice] = &MenuManager::addCircle;
    addFigureFunctions[addRectangleChoice] = &MenuManager::addRectangle;
    addFigureFunctions[addTriangleChoice] = &MenuManager::addTriangle;
}

void MenuManager::removeShapesAboveArea() {
    double area;
    if (!(cin >> area))
        throw InputException("Area must be a number");
    else {
        shapes.erase(
            std::remove_if(shapes.begin(), shapes.end(),
                           [area](Shape* a) { return a->area() > area; }
                           ),
            shapes.end()
            );
    }
}

void MenuManager::removeShape() {
    size_t index;
    if (!(cin >> index))
        throw InputException("Index must be a number");
    else {
        if (index >= shapes.size()) {
            throw out_of_range("Index out of range");
        }
        delete shapes[index];
        shapes.erase(shapes.begin() + index);
    }
}

double MenuManager::totalArea() const {
    double total = 0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

Shape* MenuManager::addCircle() {
    cout << "Input name, center and radius:\n";
    Shape* shape = new Circle();
    cin >> *shape;
    return shape;
}

Shape* MenuManager::addRectangle() {
    cout << "Input name and two points:\n";
    Shape* shape = new Rectangle();
    cin >> *shape;
    return shape;
}

Shape* MenuManager::addTriangle() {
    cout << "Input name, center and radius:\n";
    Shape* shape = new Triangle();
    cin >> *shape;
    return shape;
}

void MenuManager::printListWithParams(){
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << i + 1 << ". ";
        cout << shapes[i]->type() << "  Parameters: " << *shapes[i];
    }
}

void MenuManager::printListWithArea(){
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << i + 1 << ". ";
        cout << shapes[i]->type() << "  Area: " << shapes[i]->area() << "\n";
    }
}

void MenuManager::printTotalSum(){
    cout << "Total Area: " << totalArea() << "\n";
}

void MenuManager::sortByArea() {
    std::sort(shapes.begin(), shapes.end(), compareByArea);
}

int MenuManager::compareByArea(Shape* a, Shape* b) {
    return a->area() < b->area();
}

void MenuManager::printMenu()  {
    cout << "====================\n";
    cout << "=       MENU       =\n";
    cout << "====================\n";
    cout << "   CHOOSE COMMAND   \n";
    cout << "1. Add Figure\n";
    cout << "2. Print List of shapes with their parameters\n";
    cout << "3. Print List of shapes with their areas\n";
    cout << "4. Print Total sum of area\n";
    cout << "5. Sort Shapes by Area\n";
    cout << "6. Remove Shape by Index\n";
    cout << "7. Remove Shapes with Area Above\n";
    cout << "0. Exit :c\n";
}

void MenuManager::printSubMenu() {
    cout << "1: Circle\n"
         << "2: Rectangle\n"
         << "3: Triangle\n";
}
