#include "book.h"

Book::Book(QString title, QString author)
    : Item::Item(title), author(author)
{
}

Book::Book(int id, QString title, QString author)
    : Item::Item(id, title), author(author)
{
}

void Book::accept(Visitor *visitor)
{
    visitor->visitBook(this);
}

QString Book::getAuthor() const
{
    return author;
}

void Book::setAuthor(QString newAuthor)
{
    author = newAuthor;
}
