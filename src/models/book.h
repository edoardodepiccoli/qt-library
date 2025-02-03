#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include "item.h"
#include "../visitors/visitor.h"

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

    void debug() const override;
    void accept(Visitor *visitor) override;
};

#endif // BOOK_H