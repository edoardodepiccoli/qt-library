#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QDebug>

class Visitor; // Forward declaration

class Item
{
private:
    int id;
    QString title;

    static int generateRandomId();

public:
    Item(int id, QString title);
    Item(QString title);
    virtual ~Item();

    int getId() const;
    QString getTitle() const;

    void setId(int id);
    void setTitle(const QString &title);

    virtual void debug() const;
    virtual void accept(Visitor *visitor) = 0;
};

#endif // ITEM_H