#include "book.h"

Book::Book(QString title, QString author)
    : Item::Item(title), author(author)
{
}

QString Book::getAuthor() const
{
    return author;
}

void Book::setAuthor(QString newAuthor)
{
    author = newAuthor;
}
