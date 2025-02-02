#ifndef LIBRARY_H
#define LIBRARY_H

#include "item.h"
#include <vector>

class Library
{
private:
    std::vector<Item *> items;
public:
    Library();

    void addItem(Item *item);
    void debugItems() const;
    void saveItems() const;
};

#endif // LIBRARY_H
