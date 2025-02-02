#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
private:
    int id;
    QString title;

public:
    Item(int id, QString title);
    virtual ~Item();
};

#endif // ITEM_H