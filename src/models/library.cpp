#include "library.h"

void Library::addItem(std::unique_ptr<Item> item)
{
    items.push_back(std::move(item));
}

void Library::removeItem(int id)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            items.erase(it);
            break;
        }
    }
}

Item *Library::getItem(int id) const
{
    for (const auto &item : items)
    {
        if (item->getId() == id)
        {
            return item.get();
        }
    }
    return nullptr;
}

std::vector<Item *> Library::getAllItems() const
{
    std::vector<Item *> result;
    for (const auto &item : items)
    {
        result.push_back(item.get());
    }
    return result;
}