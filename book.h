#ifndef BOOK_H
#define BOOK_H

#include "item.h"

class Book : public Item
{
private:
    QString author;
public:
    Book(QString title, QString author);

    virtual void accept(Visitor *visitor);

    QString getAuthor() const;
    void setAuthor(QString newAuthor);
};

#endif // BOOK_H
