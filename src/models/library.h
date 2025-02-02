#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include "item.h"

class Library
{
private:
    std::vector<std::unique_ptr<Item>> items;
    QString jsonStoragePath;

public:
    Library();

    void addItem(std::unique_ptr<Item> item);
    void removeItem(int id);
    Item *getItem(int id) const;
    std::vector<Item *> getAllItems() const;
    void deleteAllItems();

    void saveItemsToJsonStorage(const QString &filePath) const;
    void loadItemsFromJsonStorage(const QString &filePath);
};

#endif // LIBRARY_H