#include "item.h"
#include <QRandomGenerator>

int Item::generateRandomId()
{
    return QRandomGenerator::global()->bounded(1, 1000000000); // Adjust range as needed
}

Item::Item(int id, QString title) : id(id), title(title)
{
}

Item::Item(QString title) : id(generateRandomId()), title(title)
{
}
