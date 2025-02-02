#include "book.h"

Book::Book(int id, QString title, QString author)
    : Item(id, title), author(author)
{
}

Book::Book(QString title, QString author)
    : Item(title), author(author)
{
}

Book::~Book()
{
}

QString Book::getAuthor() const
{
    return author;
}

void Book::setAuthor(const QString &author)
{
    this->author = author;
}
