#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include "item.h"

class Library
{
private:
    std::vector<std::unique_ptr<Item>> items;

public:
    void addItem(std::unique_ptr<Item> item);
    void removeItem(int id);
    Item *getItem(int id) const;
    std::vector<Item *> getAllItems() const;
};

#endif // LIBRARY_H