#include "item.h"

#include <QRandomGenerator>

int Item::generateRandomId()
{
    return QRandomGenerator::global()->bounded(1, 1000000000);
}

Item::Item(int id, QString title) : id(id), title(title)
{
}

Item::Item(QString title) : id(generateRandomId()), title(title)
{
}

Item::~Item()
{
}

int Item::getId() const
{
    return id;
}

QString Item::getTitle() const
{
    return title;
}

void Item::setId(int id)
{
    this->id = id;
}

void Item::setTitle(const QString &title)
{
    this->title = title;
}

void Item::debug() const
{
    qDebug() << "Item - ID:" << id << ", Title:" << title;
}