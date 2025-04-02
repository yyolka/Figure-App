#ifndef OUTPUT_H
#define OUTPUT_H

#include "actions.h"

class Output
{
public:
    static void printListWithParams(const CollectionActions& collection);
    static void printListWithArea(const CollectionActions& collection);
    static void printTotalSum(const CollectionActions& collection);
    static void printMenu();
};

#endif // OUTPUT_H
