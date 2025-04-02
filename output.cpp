#include "output.h"

void Output::printListWithParams(const CollectionActions& collection){
    for (size_t i = 0; i < collection.shapes.size(); ++i) {
        std::cout << i + 1 << ". ";
        std::cout << collection.shapes[i]->type() << "  Parameters: " << *collection.shapes[i];
    }
}

void Output::printListWithArea(const CollectionActions& collection){
    for (size_t i = 0; i < collection.shapes.size(); ++i) {
        std::cout << i + 1 << ". ";
        std::cout << collection.shapes[i]->type() << "  Area: " << collection.shapes[i]->area() << "\n";
    }
}

void Output::printTotalSum(const CollectionActions& collection){
    std::cout << "Total Area: " << collection.totalArea() << "\n";
}

void Output::printMenu()  {
    std::cout << "====================\n";
    std::cout << "=       MENU       =\n";
    std::cout << "====================\n";
    std::cout << "   CHOOSE COMMAND   \n";
    std::cout << "1. Add Circle\n";
    std::cout << "2. Add Rectangle\n";
    std::cout << "3. Add Triangle\n";
    std::cout << "4. Print List of shapes with their parameters\n";
    std::cout << "5. Print List of shapes with their areas\n";
    std::cout << "6. Print Total sum of area\n";
    std::cout << "7. Sort Shapes by Area\n";
    std::cout << "8. Remove Shape by Index\n";
    std::cout << "9. Remove Shapes with Area Above\n";
    std::cout << "0. Exit :c\n";
}
