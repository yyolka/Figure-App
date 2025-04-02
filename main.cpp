#include <iostream>
#include "actions.h"

using namespace std;

int main() {
    CollectionActions collection;
    ActionChoice choice;
    do {
        Menu.printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        try {
            switch (choice) {
            case ONE: {
                collection.addCircle();
                break;
            }
            case TWO: {
                collection.addRectangle();
                break;
            }
            case THREE: {
                collection.addTriangle();
                break;
            }
            case FOUR:
                collection.printShapes();
                break;
            case FIVE:
                collection.printAreas();
                break;
            case SIX:
                printTotalSum();
                break;
            case SEVEN:
                collection.sortByArea();
                std::cout << "Shapes sorted by area.\n";
                break;
            case EIGHT: {
                size_t index;
                std::cout << "Enter index: ";
                std::cin >> index;
                collection.removeShape(index - 1);
                break;
            }
            case NINE: {
                double area;
                std::cout << "Enter area: ";
                std::cin >> area;
                collection.removeShapesAboveArea(area);
                break;
            }
            case ZERO:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}
