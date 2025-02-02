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

    std::vector<Item *> getItems() const;

    void addItem(Item *item);
    void deleteItem(int id);
    void debugItems() const;
    void saveItems() const;
    void loadItems();
};

#endif // LIBRARY_H
