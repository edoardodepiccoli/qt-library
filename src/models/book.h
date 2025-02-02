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

    QString getAuthor() const;
    void setAuthor(const QString &author);
};

#endif // BOOK_H