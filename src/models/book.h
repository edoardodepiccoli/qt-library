#ifndef BOOK_H
#define BOOK_H

#include <QString>

#include "item.h"

class Book : public Item
{
private:
    QString author;

public:
    Book(int id, QString title, QString author);
    Book(QString title, QString author);
    virtual ~Book();
};

#endif // BOOK_H