#include "item.h"

Item::Item(QString title)
    : title(title)
{
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
