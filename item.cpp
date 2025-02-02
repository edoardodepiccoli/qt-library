#include "item.h"
#include <QRandomGenerator>

Item::Item(QString title)
    : title(title)
{
    id = QRandomGenerator::global()->bounded(0, 1000000001);
}

Item::Item(int id, QString title)
    : title(title), id(id)
{
    id = QRandomGenerator::global()->bounded(0, 1000000001);
}

void Item::accept(Visitor *visitor)
{
    visitor->visitItem(this);
}

int Item::getId() const
{
    return id;
}

void Item::setId(int newId)
{
    id = newId;
}

QString Item::getTitle() const
{
    return title;
}

void Item::setTitle(QString newTitle)
{
    title = newTitle;
}
