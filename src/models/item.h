#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
private:
    QString title;
    int id;

    static int generateRandomId();

public:
    Item(int id, QString title);
    Item(QString title);
    virtual ~Item();
};

#endif // ITEM_H