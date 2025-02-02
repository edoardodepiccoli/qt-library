#ifndef ITEM_H
#define ITEM_H

#include "visitor.h"
#include <QString>

class Item
{
private:
    QString title;
    int id;
public:
    Item(QString title);
    Item(int id, QString title);
    virtual ~Item() = default;

    virtual void accept(Visitor *visitor);

    virtual int getId() const;
    virtual void setId(int newId);

    virtual QString getTitle() const;
    virtual void setTitle(QString newTitle);
};

#endif // ITEM_H
