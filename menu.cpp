#include "menu.h"

int main() {
    CollectionActions collection;
    int choice;
    do {
        Output::printMenu();
        std::cout << "Enter your choice: ";
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: ";
        }
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
                Output::printListWithParams(collection);
                break;
            case FIVE:
                Output::printListWithArea(collection);
                break;
            case SIX:
                Output::printTotalSum(collection);
                break;
            case SEVEN:
                collection.sortByArea();
                break;
            case EIGHT: {
                size_t index;
                std::cout << "Enter index: ";
                if (!(std::cin >> index)) {
                    throw InputException("Index must be a number");
                }
                collection.removeShape(index - 1);
                break;
            }
            case NINE: {
                double area;
                std::cout << "Enter area: ";
                if (!(std::cin >> area)) {
                    throw InputException("Area must be a number");
                }
                collection.removeShapesAboveArea(area);
                break;
            }
            case ZERO:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
            }
        } catch (const InvalidTriangleException& e) {
        std::cerr << "Triangle error: " << e.what() << std::endl;
        } catch (const InvalidCircleException& e) {
            std::cerr << "Circle error: " << e.what() << "\n";
        } catch (const InvalidRectangleException e) {
            std::cerr << "Rectangle error: " << e.what() << "\n";
        } catch (const InputException e) {
            std::cerr << "Input error: " << e.what() << "\n";
        } catch (const std::out_of_range e) {
            std::cerr << "Error: " << e.what() << "\n";
        } catch (...) {
            std::cerr << "Unknown error occurred.\n";
        }
    } while (choice != 0 );

    return 0;
}

